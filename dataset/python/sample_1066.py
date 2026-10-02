import numpy as np

def forward_pass(matrix, weights, bias):
    return np.dot(matrix, weights) + bias

def recursive_forward(matrix, weights_list, bias_list, index):
    result = forward_pass(matrix, weights_list[index], bias_list[index])
    if index < len(weights_list) - 1:
        return recursive_forward(result, weights_list, bias_list, index + 1)
    else:
        return recursive_forward(result, weights_list, bias_list, 0)

def main():
    data = np.random.rand(10, 5)
    weights = [np.random.rand(5, 5) for _ in range(3)]
    biases = [np.random.rand(5) for _ in range(3)]
    recursive_forward(data, weights, biases, 0)
main()