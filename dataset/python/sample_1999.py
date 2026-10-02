import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def forward_pass(weights, biases, inputs):
    z = np.dot(weights, inputs) + biases
    return sigmoid(z)

def main():
    np.random.seed(0)
    weights = np.random.randn(10, 5)
    biases = np.random.randn(10)
    inputs = np.random.randn(5, 1)
    output = forward_pass(weights, biases, inputs)
    print(output)
if __name__ == '__main__':
    main()