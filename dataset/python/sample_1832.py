import numpy as np

def matrix_ops(a, b):
    x = np.dot(a, b)
    y = np.add(x, np.transpose(x))
    z = np.linalg.inv(y)
    return np.sum(z)

def main():
    a = np.random.rand(3, 3)
    b = np.random.rand(3, 3)
    result = matrix_ops(a, b)
    print(result)
main()