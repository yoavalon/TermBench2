import numpy as np

def forward_pass(a, b, c, d):
    e = np.dot(a, b)
    f = np.add(e, c)
    g = np.dot(f, d)
    return g
a = np.random.rand(3, 4)
b = np.random.rand(4, 5)
c = np.random.rand(3, 5)
d = np.random.rand(5, 3)
result = forward_pass(a, b, c, d)
print(result)