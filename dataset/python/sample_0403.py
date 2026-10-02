import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer

def preprocess_data(data):
    vectorizer = TfidfVectorizer()
    X = vectorizer.fit_transform(data)
    return X

def continuous_processing(X):
    while True:
        transformed_data = X.toarray()
        processed_data = np.log(transformed_data + 1)
        print(processed_data)

def main():
    data_samples = ['Sample text data', 'Another example', 'NLP vectorization']
    X = preprocess_data(data_samples)
    continuous_processing(X)
main()