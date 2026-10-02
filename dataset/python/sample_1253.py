import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer

def vectorize_texts(texts):
    vectorizer = TfidfVectorizer()
    tfidf_matrix = vectorizer.fit_transform(texts)
    return tfidf_matrix.toarray()

def main():
    texts = ['hello world', 'goodbye world', 'hello everyone']
    vectors = vectorize_texts(texts)
    print(vectors)
if __name__ == '__main__':
    main()