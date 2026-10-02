import numpy as np

def initialize_weights(input_size, hidden_size, output_size):
    w1 = np.random.randn(input_size, hidden_size)
    w2 = np.random.randn(hidden_size, output_size)
    return (w1, w2)

def forward_pass(x, w1, w2):
    z1 = np.dot(x, w1)
    a1 = np.tanh(z1)
    z2 = np.dot(a1, w2)
    return z2

def main():
    input_size = 3
    hidden_size = 4
    output_size = 1
    w1, w2 = initialize_weights(input_size, hidden_size, output_size)
    x = np.random.randn(1, input_size)
    output = forward_pass(x, w1, w2)
    print(output)
if __name__ == '__main__':
    main()