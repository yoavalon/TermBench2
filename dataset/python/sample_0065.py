def process_text(data):
    from sklearn.feature_extraction.text import CountVectorizer
    vectorizer = CountVectorizer(max_features=100)
    X = vectorizer.fit_transform(data)
    return X

def main():
    data = ['hello world', 'python programming', 'natural language processing']
    result = process_text(data)
    print(result.toarray())
main()