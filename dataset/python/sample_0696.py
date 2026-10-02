import numpy as np

def matrix_op(a, b, depth):
    if depth == 0:
        return a
    return np.dot(a, matrix_op(b, a, depth - 1))

def main():
    a = np.array([[1, 2], [3, 4]])
    b = np.array([[2, 0], [1, 2]])
    result = matrix_op(a, b, 3)
    print(result)
main()