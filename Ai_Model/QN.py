import os
import numpy as np
import torch
import torch.nn as nn
import tensorflow as tf
from onnx_tf.backend import prepare
import onnx

class MyModel(nn.Module):
    def __init__(self):
        super(MyModel, self).__init__()
        self.conv = nn.Conv2d(1, 16, kernel_size=3, padding=1)
        self.relu = nn.ReLU()
        self.fc = nn.Linear(16 * 28 * 28, 10)

    def forward(self, x):
        x = self.relu(self.conv(x))
        x = x.view(x.size(0), -1)
        return self.fc(x)

pytorch_model = MyModel()
pytorch_model.eval()

dummy_input = torch.randn(1, 1, 28, 28)
onnx_path = "model.onnx"

torch.onnx.export(
    pytorch_model,
    dummy_input,
    onnx_path,
    export_params=True,
    opset_version=11,
    do_constant_folding=True,
    input_names=['input'],
    output_names=['output']
)
print("1. Model successfully exported to ONNX format.")

onnx_model = onnx.load(onnx_path)
tf_rep = prepare(onnx_model)
tf_model_path = "tf_saved_model"
tf_rep.export_graph(tf_model_path)
print("2. ONNX model successfully converted to TensorFlow SavedModel.")

def representative_data_gen():
    for _ in range(100):
        data = np.random.rand(1, 28, 28, 1).astype(np.float32) 
        yield [data]

converter = tf.lite.TFLiteConverter.from_saved_model(tf_model_path)
converter.optimizations = [tf.lite.Optimize.DEFAULT]
converter.representative_dataset = representative_data_gen

converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
converter.inference_input_type = tf.int8
converter.inference_output_type = tf.int8

tflite_quant_model = converter.convert()

tflite_model_path = "model_quantized_int8.tflite"
with open(tflite_model_path, "wb") as f:
    f.write(tflite_quant_model)

print(f"3. Success! Full Int8 Quantized model saved as: {tflite_model_path}")