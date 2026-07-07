import torch
import torch.nn.functional as F
from PIL import Image
import torchvision.transforms as transforms
import argparse
import sys
import os

from model_F4 import TinyObstacleNetMCU

def load_image(image_path, size=(96, 96)):

    img = Image.open(image_path).convert('L')  # L = grayscale
    transform = transforms.Compose([
        transforms.Resize(size),
        transforms.ToTensor(),          # مقدار پیکسل‌ها در بازه [0, 1]
    ])
    img_tensor = transform(img)         # شکل: (1, 96, 96)
    img_tensor = img_tensor.unsqueeze(0)  # افزودن بُعد دسته -> (1, 1, 96, 96)
    return img_tensor

def main():
    parser = argparse.ArgumentParser(description='تست TinyObstacleNetMCU روی یک تصویر.')
    parser.add_argument('image_path', type=str, help='D:\\CreateProject\\TinyML_Obstacle Detection\\obs_0.png')
    parser.add_argument('--checkpoint', type=str, default=None,
                        help='D:\\CreateProject\\TinyML_Obstacle Detection\\Ai_Model\\best_tiny_model.pth')
    parser.add_argument('--device', type=str, default='cpu',
                        help='دستگاه محاسباتی: cpu یا cuda (در صورت در دسترس بودن)')
    args = parser.parse_args()

    # انتخاب دستگاه
    device = torch.device(args.device if (args.device == 'cuda' and torch.cuda.is_available()) else 'cpu')
    print(f"استفاده از دستگاه: {device}")

    # بارگذاری مدل
    model = TinyObstacleNetMCU().to(device)
    if args.checkpoint and os.path.isfile(args.checkpoint):
        print(f"بارگذاری checkpoint از {args.checkpoint}")
        state_dict = torch.load(args.checkpoint, map_location=device)
        model.load_state_dict(state_dict)
    else:
        print("هیچ checkpoint معتبری یافت نشد. مدل با وزن‌های تصادفی مقداردهی می‌شود.")

    model.eval()  # غیرفعال کردن Dropout و BatchNorm در حالت ارزیابی

    # بارگذاری و پیش‌پردازش تصویر
    img_tensor = load_image(args.image_path)
    img_tensor = img_tensor.to(device)

    # اجرای استنتاج
    with torch.no_grad():
        output = model(img_tensor)          # خروجی: (1, 1)
        prob = output.item()                # مقدار احتمال (اسکالر)
        print(f"احتمال خروجی: {prob:.4f}")
        # تصمیم‌گیری بر اساس آستانه ۰.۵
        prediction = "Obstacle" if prob > 0.5 else "No obstacle"
        print(f"پیش‌بینی: {prediction}")

if __name__ == '__main__':
    main()