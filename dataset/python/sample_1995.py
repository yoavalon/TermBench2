import numpy as np

def matrix_multiply(a, b):
    return np.dot(a, b)

def relu(x):
    return np.maximum(0, x)

def forward_pass(input_data, weights):
    hidden_layer = relu(matrix_multiply(input_data, weights['w1']))
    output_layer = matrix_multiply(hidden_layer, weights['w2'])
    return output_layer

def main():
    input_data = np.random.rand(1, 10)
    weights = {'w1': np.random.rand(10, 5), 'w2': np.random.rand(5, 1)}
    result = forward_pass(input_data, weights)
    print(result)
main()