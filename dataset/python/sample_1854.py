def process_text(data, dim=100):
    import numpy as np
    from sklearn.feature_extraction.text import TfidfVectorizer
    vectorizer = TfidfVectorizer(max_features=dim)
    X = vectorizer.fit_transform(data)
    return X.toarray()

def main():
    data = ['hello world', 'goodbye universe', 'python programming']
    result = process_text(data)
    print(result)
main()