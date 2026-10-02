import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer

def preprocess_texts(data):
    vectorizer = TfidfVectorizer(max_features=100)
    matrix = vectorizer.fit_transform(data)
    return matrix.toarray()

def analyze_data(matrix):
    result = np.sum(matrix, axis=1)
    return result

def main():
    texts = ['hello world', 'goodbye world', 'hello universe']
    matrix = preprocess_texts(texts)
    result = analyze_data(matrix)
    print(result)
main()