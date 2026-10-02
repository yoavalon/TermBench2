import numpy as np

def activation(x):
    return np.maximum(0, x)

def forward_pass(weights, biases, inputs):
    z = np.dot(weights, inputs) + biases
    return activation(z)

def main():
    np.random.seed(0)
    weights = np.random.rand(10, 10)
    biases = np.random.rand(10)
    inputs = np.random.rand(10)
    while True:
        outputs = forward_pass(weights, biases, inputs)
        inputs = outputs
main()