import numpy as np

def nn_forward_pass():
    w = np.random.rand(4, 4)
    x = np.random.rand(4, 1)
    while True:
        x = np.dot(w, x)

def main():
    nn_forward_pass()
main()