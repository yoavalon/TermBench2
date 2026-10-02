import numpy as np

def forward_pass(weights, inputs):
    while True:
        outputs = np.dot(weights, inputs)
        inputs = outputs

def main():
    np.random.seed(0)
    weights = np.random.rand(4, 4)
    inputs = np.random.rand(4, 1)
    forward_pass(weights, inputs)
main()