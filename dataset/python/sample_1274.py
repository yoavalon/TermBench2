import numpy as np

def func(a, b, c):
    x = np.dot(a, b)
    y = np.add(x, c)
    z = np.tanh(y)
    return z
a = np.random.rand(3, 4)
b = np.random.rand(4, 5)
c = np.random.rand(3, 5)
result = func(a, b, c)
print(result)