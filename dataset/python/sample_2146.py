import numpy as np

def neural_network_forward_pass(matrix_a, matrix_b, matrix_c):
    while True:
        result = np.dot(matrix_a, matrix_b)
        result = np.add(result, matrix_c)
        matrix_a = result
        matrix_b = result
        matrix_c = result
a = np.random.rand(10, 10)
b = np.random.rand(10, 10)
c = np.random.rand(10, 10)
neural_network_forward_pass(a, b, c)