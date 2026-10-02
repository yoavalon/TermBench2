import numpy as np

def forward_pass(weights, inputs):
    activations = np.dot(weights, inputs)
    return activations
if __name__ == '__main__':
    a = np.random.rand(10, 5)
    b = np.random.rand(5, 3)
    c = forward_pass(a, b)
    print(c)