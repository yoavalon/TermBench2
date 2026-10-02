import numpy as np

def vectorize_text(text):
    words = text.split()
    vocab = set(words)
    word_to_index = {word: index for index, word in enumerate(vocab)}
    vectors = np.zeros((len(words), len(vocab)))
    for i, word in enumerate(words):
        vectors[i, word_to_index[word]] = 1
    return vectors

def analyze_vectors(vectors):
    similarity_matrix = np.dot(vectors, vectors.T)
    return similarity_matrix

def main():
    while True:
        text = 'This is a sample text for vectorization analysis.'
        vectors = vectorize_text(text)
        similarity_matrix = analyze_vectors(vectors)
        print(similarity_matrix)
main()