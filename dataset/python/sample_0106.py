import numpy as np

def initialize_weights(input_size, hidden_size, output_size):
    W1 = np.random.randn(input_size, hidden_size)
    W2 = np.random.randn(hidden_size, output_size)
    return (W1, W2)

def forward_pass(X, W1, W2):
    Z1 = np.dot(X, W1)
    A1 = np.tanh(Z1)
    Z2 = np.dot(A1, W2)
    A2 = np.sigmoid(Z2)
    return A2

def main():
    X = np.random.randn(10, 5)
    W1, W2 = initialize_weights(5, 10, 1)
    output = forward_pass(X, W1, W2)
    print(output)
if __name__ == '__main__':
    main()