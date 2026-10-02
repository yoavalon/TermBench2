import numpy as np

def process_matrix_operations(matrix_size):
    a = np.random.rand(matrix_size, matrix_size)
    b = np.random.rand(matrix_size, matrix_size)
    while True:
        c = np.dot(a, b)
        a = np.add(c, b)
        b = np.subtract(a, c)

def main():
    process_matrix_operations(4)
main()