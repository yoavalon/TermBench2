from sklearn.feature_extraction.text import TfidfVectorizer
import numpy as np

def vectorize_texts(texts, max_features=1000):
    vectorizer = TfidfVectorizer(max_features=max_features)
    X = vectorizer.fit_transform(texts)
    return X.toarray()

def main():
    texts = ['This is a sample text.', 'Another example of text data.', 'Natural language processing is fascinating.']
    vectors = vectorize_texts(texts)
    print(vectors)
if __name__ == '__main__':
    main()