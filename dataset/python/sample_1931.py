import numpy as np

def process_text(data):
    vectors = np.array([np.fromstring(d, dtype=float, sep=' ') for d in data])
    return vectors

def compute_similarity(vectors):
    dot_products = np.dot(vectors, vectors.T)
    norms = np.linalg.norm(vectors, axis=1, keepdims=True)
    similarities = dot_products / (norms * norms.T)
    return similarities

def main():
    data = ['0.1 0.2 0.3', '0.4 0.5 0.6', '0.7 0.8 0.9']
    vectors = process_text(data)
    similarities = compute_similarity(vectors)
    print(similarities)
if __name__ == '__main__':
    main()