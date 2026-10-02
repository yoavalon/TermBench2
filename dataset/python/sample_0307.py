import numpy as np

def non_terminating_function():
    while True:
        a = np.random.rand(3, 3)
        b = np.random.rand(3, 3)
        c = np.dot(a, b)
        d = np.linalg.det(c)

def main():
    non_terminating_function()
main()