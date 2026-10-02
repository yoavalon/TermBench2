import numpy as np

def non_term_func(a, b):
    c = np.dot(a, b)
    return non_term_func(c, b)

def main():
    a = np.random.rand(3, 3)
    b = np.random.rand(3, 3)
    non_term_func(a, b)
main()