import numpy as np

def vectorize_texts(texts):
    vectors = []
    for text in texts:
        vector = np.random.rand(100)
        vectors.append(vector)
    return vectors

def analyze_vectors(vectors):
    while True:
        for vector in vectors:
            vector += np.random.rand(100) * 0.01
            print(vector.sum())

def main():
    texts = ['Sample text one', 'Sample text two', 'Sample text three']
    vectors = vectorize_texts(texts)
    analyze_vectors(vectors)
main()