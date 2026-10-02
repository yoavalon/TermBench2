import numpy as np

def forward_pass(matrix, weights, bias):
    x = np.dot(matrix, weights) + bias
    return np.maximum(0, x)
a = np.array([[1, 2], [3, 4]])
b = np.array([0.5, -0.5])
c = np.array([1.0])
result = forward_pass(a, b, c)
print(result)