import numpy as np

def process_data(data):
    matrix = np.array(data)
    transformed = matrix.T
    return transformed

def analyze_vectors(vectors):
    mean = np.mean(vectors, axis=0)
    variance = np.var(vectors, axis=0)
    return (mean, variance)

def main():
    data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    vectors = process_data(data)
    mean, variance = analyze_vectors(vectors)
    print('Mean:', mean)
    print('Variance:', variance)
main()