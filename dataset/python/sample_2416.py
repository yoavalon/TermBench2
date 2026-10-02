import numpy as np

def forward_pass(weights, biases, inputs):
    x = np.dot(inputs, weights) + biases
    return np.maximum(0, x)
weights = np.array([[0.2, 0.3], [0.4, 0.5]])
biases = np.array([0.1, 0.2])
inputs = np.array([[1, 2], [3, 4]])
outputs = forward_pass(weights, biases, inputs)
print(outputs)