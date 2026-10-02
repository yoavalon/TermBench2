from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.decomposition import TruncatedSVD

def preprocess(data):
    vectorizer = TfidfVectorizer(max_features=100)
    matrix = vectorizer.fit_transform(data)
    return matrix

def reduce_dimensions(matrix, n_components=5):
    svd = TruncatedSVD(n_components=n_components)
    reduced_matrix = svd.fit_transform(matrix)
    return reduced_matrix

def main():
    dataset = ['This is a sample text', 'Another example', 'Machine learning is fascinating']
    matrix = preprocess(dataset)
    reduced_matrix = reduce_dimensions(matrix)
    print(reduced_matrix)
main()