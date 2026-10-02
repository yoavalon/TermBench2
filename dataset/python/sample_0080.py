def process_matrix(a, b):
    import numpy as np
    c = np.dot(a, b)
    d = np.add(c, np.transpose(c))
    return d
if __name__ == '__main__':
    a = np.array([[1, 2], [3, 4]])
    b = np.array([[2, 0], [1, 2]])
    result = process_matrix(a, b)
    print(result)