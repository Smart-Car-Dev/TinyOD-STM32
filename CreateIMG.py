import cv2
import numpy as np

def image_to_c_array(image_path, output_txt="image_data.txt"):
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    
    if img is None:
        print("Error: Image not found!")
        return

    img = cv2.resize(img, (96, 96))
    
    flat_img = img.flatten()
    
    with open(output_txt, "w") as f:
        for i, pixel in enumerate(flat_img):
            f.write(f"0x{pixel:02X}, ")
            if (i + 1) % 12 == 0:
                f.write("\n")
                
    print(f"Success! 9216 bytes written to {output_txt}")

image_to_c_array("obs_0.png")