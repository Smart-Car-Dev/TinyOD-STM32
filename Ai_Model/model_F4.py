import torch
import torch.nn as nn
import torch.nn.functional as F

class DepthwiseSeparableConv(nn.Module):

    def __init__(self, in_channels, out_channels, stride=1):
        super().__init__()
        self.depthwise = nn.Conv2d(
            in_channels, in_channels, kernel_size=3, 
            stride=stride, padding=1, groups=in_channels, bias=False
        )
        self.pointwise = nn.Conv2d(
            in_channels, out_channels, kernel_size=1, bias=False
        )
        self.bn = nn.BatchNorm2d(out_channels)
        
    def forward(self, x):
        x = self.depthwise(x)
        x = self.pointwise(x)
        x = self.bn(x)
        return F.relu(x)

class TinyObstacleNetMCU(nn.Module):
    def __init__(self):
        super().__init__()

        self.conv1 = nn.Sequential(
            nn.Conv2d(in_channels=1, out_channels=8, kernel_size=3, stride=2, padding=1, bias=False),
            nn.BatchNorm2d(8),
            nn.ReLU()
        )
        
        self.conv2 = DepthwiseSeparableConv(in_channels=8, out_channels=16, stride=2)
        
        self.conv3 = DepthwiseSeparableConv(in_channels=16, out_channels=16, stride=1)

        self.gap = nn.AdaptiveAvgPool2d((1, 1))

        self.fc = nn.Linear(in_features=16, out_features=1)

    def forward(self, x):
        x = self.conv1(x)

        x = F.max_pool2d(x, kernel_size=2, stride=2)
        
        x = self.conv2(x)
        x = self.conv3(x)
        
        x = self.gap(x)
        x = x.view(x.size(0), -1)

        x = torch.sigmoid(self.fc(x))
        return x

if __name__ == "__main__":
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print(f"Using device: {device}\n")

    model = TinyObstacleNetMCU().to(device)
    dummy_input = torch.randn(1, 1, 96, 96).to(device)
    
    output = model(dummy_input)
    
    print(f"Input shape: {dummy_input.shape}")
    print(f"Output shape: {output.shape}\n")
    
    total_params = sum(p.numel() for p in model.parameters())
    flash_kb = (total_params * 4) / 1024
    print(f"Total Model Parameters: {total_params}")
    print(f"Estimated Flash Size: {flash_kb:.2f} KB")

    peak_activation_bytes = (8 * 48 * 48) * 4
    print(f"Estimated Peak Activation RAM (Float32): {peak_activation_bytes / 1024:.2f} KB")
    print(f"Estimated Peak Activation RAM (Quantized INT8): {(peak_activation_bytes / 1024) / 4:.2f} KB")