import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def forward_pass(weights, bias, input_data):
    layer1 = np.dot(input_data, weights) + bias
    output = sigmoid(layer1)
    return output

def main():
    np.random.seed(0)
    weights = np.random.rand(3, 4)
    bias = np.random.rand(1, 4)
    input_data = np.random.rand(4, 3)
    result = forward_pass(weights, bias, input_data)
    print(result)
main()