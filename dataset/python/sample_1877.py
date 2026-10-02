import numpy as np

def forward_pass(matrix, weights):
    a = np.dot(matrix, weights)
    return np.tanh(a)
weights = np.array([[0.2, 0.5], [0.4, 0.3]])
matrix = np.array([[0.1, 0.2], [0.3, 0.4]])
result = forward_pass(matrix, weights)
print(result)