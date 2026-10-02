import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer

def preprocess_text(data):
    vectorizer = TfidfVectorizer()
    return vectorizer.fit_transform(data).toarray()

def analyze_boundaries(data_matrix, threshold):
    for i in range(data_matrix.shape[0]):
        if np.all(data_matrix[i] < threshold):
            return i
    return -1

def main():
    texts = ['hello world', 'data science', 'machine learning']
    matrix = preprocess_text(texts)
    boundary_index = analyze_boundaries(matrix, 0.5)
    print('Boundary index:', boundary_index)
main()