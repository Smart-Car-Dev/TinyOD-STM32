import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader, random_split
from torch.optim.lr_scheduler import ReduceLROnPlateau
import os

from data_loader import TinyObstacleDataset, mcu_transforms
from model_F4 import TinyObstacleNetMCU

def train_model():
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    if device.type == 'cuda':
        torch.backends.cudnn.benchmark = True
    print(f"[*] Training on device: {device}")

    dataset_path = "./dataset"
    full_dataset = TinyObstacleDataset(root_dir=dataset_path, transform=mcu_transforms)
    
    if len(full_dataset) == 0:
        print("[!] Error: Dataset is empty. Run generate_data.py first.")
        return

    train_size = int(0.8 * len(full_dataset))
    val_size = len(full_dataset) - train_size
    train_dataset, val_dataset = random_split(full_dataset, [train_size, val_size])

    train_loader = DataLoader(train_dataset, batch_size=32, shuffle=True, num_workers=2, pin_memory=True)
    val_loader = DataLoader(val_dataset, batch_size=32, shuffle=False, num_workers=2, pin_memory=True)

    model = TinyObstacleNetMCU().to(device)
    

    criterion = nn.BCEWithLogitsLoss() 
    
    optimizer = optim.Adam(model.parameters(), lr=0.001, weight_decay=1e-4)
    
    scheduler = ReduceLROnPlateau(optimizer, mode='min', factor=0.5, patience=2, verbose=True)

    num_epochs = 30
    best_val_loss = float('inf')
    best_model_weights = "best_tiny_model_weights.pth"
    full_model_path = "best_tiny_model_complete.pth"

    print("[*] Starting Training Loop...")
    
    for epoch in range(num_epochs):
        model.train()
        running_loss = 0.0
        correct_train = 0
        total_train = 0

        for images, labels in train_loader:
            images = images.to(device, non_blocking=True)
            labels = labels.view(-1, 1).to(device, non_blocking=True).float()

            optimizer.zero_grad(set_to_none=True)

            outputs = model(images)
            loss = criterion(outputs, labels)
            
            loss.backward()
            optimizer.step()

            running_loss += loss.item()
            
            predicted = (torch.sigmoid(outputs) >= 0.5).float()
            total_train += labels.size(0)
            correct_train += (predicted == labels).sum().item()

        train_acc = 100 * correct_train / total_train
        avg_train_loss = running_loss / len(train_loader)

        model.eval()
        val_loss = 0.0
        correct_val = 0
        total_val = 0

        with torch.no_grad():
            for images, labels in val_loader:
                images = images.to(device, non_blocking=True)
                labels = labels.view(-1, 1).to(device, non_blocking=True).float()

                outputs = model(images)
                loss = criterion(outputs, labels)
                val_loss += loss.item()

                predicted = (torch.sigmoid(outputs) >= 0.5).float()
                total_val += labels.size(0)
                correct_val += (predicted == labels).sum().item()

        val_acc = 100 * correct_val / total_val
        avg_val_loss = val_loss / len(val_loader)

        scheduler.step(avg_val_loss)

        print(f"Epoch [{epoch+1}/{num_epochs}] "
              f"Train Loss: {avg_train_loss:.4f}, Train Acc: {train_acc:.2f}% | "
              f"Val Loss: {avg_val_loss:.4f}, Val Acc: {val_acc:.2f}%")

        if avg_val_loss < best_val_loss:
            best_val_loss = avg_val_loss
            
            torch.save(model.state_dict(), best_model_weights)
            
            torch.save(model, full_model_path)
            print(f"    -> Best model configurations saved (Loss: {best_val_loss:.4f})")

    print(f"[*] Training complete. Models deployment ready.")

if __name__ == "__main__":
    train_model()