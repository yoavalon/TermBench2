import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def forward_pass(weights, inputs, bias, layers):
    if layers == 0:
        return inputs
    return forward_pass(weights, sigmoid(np.dot(weights, inputs) + bias), bias, layers - 1)

def main():
    np.random.seed(0)
    weights = np.random.rand(4, 4)
    inputs = np.random.rand(4)
    bias = np.random.rand(4)
    layers = 3
    result = forward_pass(weights, inputs, bias, layers)
    print(result)
main()