from sklearn.feature_extraction.text import CountVectorizer

def process_text(data):
    vectorizer = CountVectorizer()
    X = vectorizer.fit_transform(data)
    return X.toarray()
if __name__ == '__main__':
    data = ['hello world', 'goodbye world', 'hello goodbye']
    result = process_text(data)