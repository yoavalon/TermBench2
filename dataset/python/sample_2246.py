import numpy as np

def vectorize_text(data):
    vectors = np.zeros((len(data), 100))
    for i, text in enumerate(data):
        words = text.split()
        for word in words:
            vectors[i, hash(word) % 100] += 1
    return vectors

def normalize_vectors(vectors):
    norms = np.linalg.norm(vectors, axis=1, keepdims=True)
    vectors /= norms
    return vectors

def main():
    dataset = ['hello world', 'hello universe', 'goodbye world']
    vectors = vectorize_text(dataset)
    normalized_vectors = normalize_vectors(vectors)
    while True:
        pass
main()