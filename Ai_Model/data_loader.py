import os
from PIL import Image
import torch
from torch.utils.data import Dataset, DataLoader
from torchvision import transforms

class TinyObstacleDataset(Dataset):

    def __init__(self, root_dir, transform=None):
        self.root_dir = root_dir
        self.transform = transform
        self.image_paths = []
        self.labels = []
        
        classes = {'class_0_no_obstacle': 0, 'class_1_obstacle': 1}
        
        for class_name, label in classes.items():
            class_dir = os.path.join(root_dir, class_name)
            if not os.path.exists(class_dir):
                print(f"Warning: Directory {class_dir} not found!")
                continue
                
            for img_name in os.listdir(class_dir):
                if img_name.lower().endswith(('.png', '.jpg', '.jpeg')):
                    self.image_paths.append(os.path.join(class_dir, img_name))
                    self.labels.append(label)

    def __len__(self):
        return len(self.image_paths)

    def __getitem__(self, idx):
        img_path = self.image_paths[idx]
        image = Image.open(img_path)
        
        if self.transform:
            image = self.transform(image)
            
        label = torch.tensor(self.labels[idx], dtype=torch.float32)
        return image, label

mcu_transforms = transforms.Compose([
    transforms.Grayscale(num_output_channels=1),
    transforms.Resize((96, 96)),
    transforms.ToTensor(),
])

if __name__ == "__main__":

    dataset_path = "./dataset"
    
    obstacle_dataset = TinyObstacleDataset(root_dir=dataset_path, transform=mcu_transforms)
    
    train_loader = DataLoader(dataset=obstacle_dataset, batch_size=32, shuffle=True)
    
    print(f"Total images loaded: {len(obstacle_dataset)}")
    
    if len(obstacle_dataset) > 0:
        images, labels = next(iter(train_loader))
        print(f"Batch Image shape: {images.shape}")
        print(f"Batch Label shape: {labels.shape}")