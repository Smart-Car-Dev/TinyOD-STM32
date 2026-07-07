import os
import numpy as np
from PIL import Image, ImageDraw

def create_synthetic_dataset(base_dir="dataset", num_samples=200):

    class_0_dir = os.path.join(base_dir, "class_0_no_obstacle")
    class_1_dir = os.path.join(base_dir, "class_1_obstacle")

    os.makedirs(class_0_dir, exist_ok=True)
    os.makedirs(class_1_dir, exist_ok=True)

    print(f"Generating {num_samples} images for each class...")

    for i in range(num_samples):

        bg_color = np.random.randint(100, 150)
        img_no_obstacle = np.full((96, 96), bg_color, dtype=np.uint8)
        
        noise = np.random.randint(-20, 20, (96, 96), dtype=np.int16)
        img_no_obstacle = np.clip(img_no_obstacle + noise, 0, 255).astype(np.uint8)
        
        im0 = Image.fromarray(img_no_obstacle)
        im0.save(os.path.join(class_0_dir, f"no_obs_{i}.png"))

        bg_color = np.random.randint(100, 150)
        img_obstacle = np.full((96, 96), bg_color, dtype=np.uint8)
        img_obstacle = np.clip(img_obstacle + noise, 0, 255).astype(np.uint8)
        
        im1 = Image.fromarray(img_obstacle)
        draw = ImageDraw.Draw(im1)
        
        x1 = np.random.randint(10, 50)
        y1 = np.random.randint(10, 50)
        x2 = x1 + np.random.randint(20, 40)
        y2 = y1 + np.random.randint(20, 40)
        
        obstacle_color = np.random.randint(0, 50)
        draw.rectangle([x1, y1, x2, y2], fill=obstacle_color)
        
        im1.save(os.path.join(class_1_dir, f"obs_{i}.png"))

    print(f"Dataset generated successfully at: ./{base_dir}")

if __name__ == "__main__":
    create_synthetic_dataset(num_samples=200)