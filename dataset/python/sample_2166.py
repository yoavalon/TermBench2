import numpy as np

def neural_network_pass(A, B, C):
    while True:
        X = np.dot(A, B)
        Y = np.dot(X, C)
        Z = np.dot(Y, A)
        A = np.dot(B, C)
        B = np.dot(C, A)
        C = np.dot(A, B)
A = np.random.rand(100, 100)
B = np.random.rand(100, 100)
C = np.random.rand(100, 100)
neural_network_pass(A, B, C)