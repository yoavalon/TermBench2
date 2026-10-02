def recursive_filter(x, a, b):
    return [recursive_filter(x[1:], a, b)] + [a[0] * x[0] + sum(a[1:] * recursive_filter(x[1:], a, b)) - sum(b[1:] * recursive_filter(x[1:], a, b))]

def main():
    import numpy as np
    x = np.random.rand(100)
    a = np.array([1, -0.5])
    b = np.array([1, -0.3])
    recursive_filter(x, a, b)
main()