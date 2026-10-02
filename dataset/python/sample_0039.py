from sklearn.feature_extraction.text import TfidfVectorizer

def process_texts(data):
    vectorizer = TfidfVectorizer()
    X = vectorizer.fit_transform(data)
    return X.toarray()
if __name__ == '__main__':
    texts = ['hello world', 'data science', 'python programming']
    result = process_texts(texts)
    print(result)