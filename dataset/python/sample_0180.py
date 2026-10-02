from sklearn.feature_extraction.text import TfidfVectorizer
import numpy as np

def preprocess_data(data):
    vectorizer = TfidfVectorizer()
    tfidf_matrix = vectorizer.fit_transform(data)
    return tfidf_matrix.toarray()

def analyze_vectors(vectors):
    mean_vector = np.mean(vectors, axis=0)
    variance_vector = np.var(vectors, axis=0)
    return (mean_vector, variance_vector)

def main():
    data = ['hello world', 'data science', 'machine learning']
    vectors = preprocess_data(data)
    mean, variance = analyze_vectors(vectors)
    print('Mean Vector:', mean)
    print('Variance Vector:', variance)
main()