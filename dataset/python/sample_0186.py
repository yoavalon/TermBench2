import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def forward_pass(weights, bias, input_data):
    z = np.dot(weights, input_data) + bias
    return sigmoid(z)

def main():
    np.random.seed(0)
    weights = np.random.rand(1, 3)
    bias = np.random.rand(1)
    input_data = np.array([1, 2, 3])
    output = forward_pass(weights, bias, input_data)
    print(output)
if __name__ == '__main__':
    main()