import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def forward_pass(weights, biases, inputs):
    for w, b in zip(weights, biases):
        inputs = sigmoid(np.dot(w, inputs) + b)
    return inputs

def main():
    np.random.seed(0)
    layers = 3
    input_size = 5
    output_size = 1
    hidden_size = 4
    weights = [np.random.randn(hidden_size, input_size) if i == 0 else np.random.randn(output_size, hidden_size) for i in range(layers)]
    biases = [np.random.randn(hidden_size, 1) if i == 0 else np.random.randn(output_size, 1) for i in range(layers)]
    inputs = np.random.randn(input_size, 1)
    result = forward_pass(weights, biases, inputs)
    print(result)
if __name__ == '__main__':
    main()