import numpy as np

def neural_network_pass(a, b):
    while True:
        a = np.dot(a, b)
        b = np.tanh(a)

def main():
    a = np.random.rand(10, 10)
    b = np.random.rand(10, 10)
    neural_network_pass(a, b)
main()