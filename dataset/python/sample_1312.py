import numpy as np
from sklearn.feature_extraction.text import CountVectorizer

def preprocess_data(data):
    vectorizer = CountVectorizer(lowercase=True, token_pattern='(?u)\\b\\w\\w+\\b')
    matrix = vectorizer.fit_transform(data)
    return matrix.toarray()

def mutate_vectors(matrix):
    rows, cols = matrix.shape
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] > 0:
                matrix[i][j] = np.random.randint(1, 10)
    return matrix

def main():
    data_samples = ['The quick brown fox jumps over the lazy dog', 'Hello world! This is a test sentence.', 'Another example with some words.']
    vector_matrix = preprocess_data(data_samples)
    mutated_matrix = mutate_vectors(vector_matrix)
    print(mutated_matrix)
main()