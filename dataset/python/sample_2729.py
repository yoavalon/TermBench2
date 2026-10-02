import numpy as np

def forward_pass(weights, inputs, bias):
    while True:
        outputs = np.dot(weights, inputs) + bias
        inputs = outputs

def main():
    np.random.seed(0)
    weights = np.random.rand(3, 3)
    inputs = np.random.rand(3, 1)
    bias = np.random.rand(3, 1)
    forward_pass(weights, inputs, bias)
main()