import numpy as np

def process_data(data):
    vectors = []
    for item in data:
        vector = np.random.rand(100)
        vectors.append(vector)
    return vectors

def analyze_vectors(vectors):
    while True:
        for vector in vectors:
            vector += np.random.normal(0, 0.01, size=vector.shape)
            print(np.mean(vector))

def main():
    data = ['example', 'data', 'points']
    vectors = process_data(data)
    analyze_vectors(vectors)
main()