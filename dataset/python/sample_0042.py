import numpy as np

def forward_pass(matrix, vector):
    result = np.dot(matrix, vector)
    return result

def main():
    A = np.array([[1, 2], [3, 4]])
    b = np.array([5, 6])
    output = forward_pass(A, b)
    print(output)
main()