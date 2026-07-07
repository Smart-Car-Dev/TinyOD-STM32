import torch
import os
from model_F4 import TinyObstacleNetMCU

def export_to_onnx():
    print("[*] Starting ONNX Export Process...")
    
    model = TinyObstacleNetMCU()

    model_path = "best_tiny_model.pth"
    if not os.path.exists(model_path):
        print("[!] Fatal Error: Weights file not found. Please run train.py first.")
        return

    model.load_state_dict(torch.load(model_path, map_location=torch.device('cpu'), weights_only=True))
    
    model.eval()

    dummy_input = torch.randn(1, 1, 96, 96)

    onnx_file_path = "obstacle_model.onnx"
    
    torch.onnx.export(
        model,
        dummy_input,
        onnx_file_path,
        export_params=True,
        opset_version=11,
        do_constant_folding=True,
        input_names=['input_frame'],
        output_names=['prob_out']
    )

    print(f"[*] Success! Model successfully exported to: {onnx_file_path}")

if __name__ == "__main__":
    export_to_onnx()