import numpy as np

def forward_pass(matrix, vector):
    result = np.dot(matrix, vector)
    return result

def main():
    matrix = np.array([[0.1, 0.2], [0.3, 0.4]], dtype=np.float32)
    vector = np.array([0.5, 0.6], dtype=np.float32)
    output = forward_pass(matrix, vector)
    print(output)
main()