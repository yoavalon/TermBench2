import numpy as np

def relu(x):
    return np.maximum(0, x)

def forward_pass(weights, biases, input_data):
    layer_output = input_data
    for w, b in zip(weights, biases):
        layer_output = relu(np.dot(layer_output, w) + b)
    return layer_output

def main():
    input_data = np.random.rand(1, 10)
    weights = [np.random.rand(10, 20), np.random.rand(20, 1)]
    biases = [np.random.rand(1, 20), np.random.rand(1, 1)]
    while True:
        output = forward_pass(weights, biases, input_data)
        print(output)
main()