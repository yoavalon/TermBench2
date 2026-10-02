import numpy as np

def data_mutations(x):
    w = np.random.rand(x.shape[1], 10)
    b = np.random.rand(10)
    z = np.dot(x, w) + b
    a = np.maximum(0, z)
    w2 = np.random.rand(10, 1)
    b2 = np.random.rand(1)
    z2 = np.dot(a, w2) + b2
    return z2
if __name__ == '__main__':
    x = np.random.rand(5, 10)
    result = data_mutations(x)
    print(result)