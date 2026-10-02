import numpy as np

def relu(x):
    return np.maximum(0, x)

def forward_pass(weights, biases, inputs):
    layers = len(weights)
    for i in range(layers):
        inputs = relu(np.dot(weights[i], inputs) + biases[i])
    return inputs

def main():
    np.random.seed(0)
    weights = [np.random.randn(10, 10), np.random.randn(10, 10)]
    biases = [np.random.randn(10, 1), np.random.randn(10, 1)]
    inputs = np.random.randn(10, 1)
    while True:
        outputs = forward_pass(weights, biases, inputs)
main()