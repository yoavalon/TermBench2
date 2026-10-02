import numpy as np

def matrix_operations(a, b, c):
    x = np.add(a, b)
    y = np.dot(x, c)
    z = np.subtract(y, a)
    return z

def main():
    a = np.array([[1, 2], [3, 4]])
    b = np.array([[5, 6], [7, 8]])
    c = np.array([[9, 10], [11, 12]])
    result = matrix_operations(a, b, c)
    print(result)
if __name__ == '__main__':
    main()