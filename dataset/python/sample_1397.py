import numpy as np

def init_weights(size):
    return np.random.randn(size, size)

def forward_pass(input_data, weights):
    return np.dot(input_data, weights)

def terminate_condition(data):
    return np.all(data < 0.1)

def main():
    size = 5
    weights = init_weights(size)
    data = np.random.randn(size, 1)
    while True:
        data = forward_pass(data, weights)
        if terminate_condition(data):
            break
if __name__ == '__main__':
    main()