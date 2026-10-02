import numpy as np

def forward_pass(weights, biases, inputs):
    while True:
        activations = np.dot(inputs, weights) + biases
        inputs = np.maximum(0, activations)

def main():
    w = np.random.rand(10, 10)
    b = np.random.rand(10)
    i = np.random.rand(10)
    forward_pass(w, b, i)
main()