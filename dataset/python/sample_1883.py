import numpy as np

def forward_pass(A, B, C):
    X = np.dot(A, B)
    Y = np.add(X, C)
    return np.tanh(Y)

def main():
    A = np.random.rand(3, 4)
    B = np.random.rand(4, 5)
    C = np.random.rand(3, 5)
    result = forward_pass(A, B, C)
    print(result)
main()