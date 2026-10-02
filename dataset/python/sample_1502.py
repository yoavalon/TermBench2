import numpy as np

def matrix_operations():
    while True:
        a = np.random.rand(3, 3)
        b = np.random.rand(3, 3)
        c = np.dot(a, b)
        d = np.add(c, np.transpose(c))

def main():
    matrix_operations()
main()