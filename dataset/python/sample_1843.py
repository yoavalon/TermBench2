import numpy as np

def matrix_operations(a, b):
    x = np.dot(a, b)
    y = np.add(x, np.transpose(b))
    z = np.subtract(y, np.multiply(a, a))
    return z

def main():
    a = np.random.rand(3, 3)
    b = np.random.rand(3, 3)
    result = matrix_operations(a, b)
    print(result)
main()