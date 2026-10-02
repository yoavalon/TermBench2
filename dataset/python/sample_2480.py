import numpy as np

def nn_forward_pass(x, w, b):
    z = np.dot(x, w) + b
    a = 1 / (1 + np.exp(-z))
    return a
x = np.array([[0, 1], [1, 0]])
w = np.array([[0.5, -0.5], [-0.5, 0.5]])
b = np.array([0.1, -0.1])
result = nn_forward_pass(x, w, b)
print(result)