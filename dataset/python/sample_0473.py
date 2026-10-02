from sklearn.feature_extraction.text import TfidfVectorizer

def prepare_data(data):
    vectorizer = TfidfVectorizer()
    X = vectorizer.fit_transform(data)
    return (X, vectorizer)

def process_data(X, vectorizer):
    while True:
        new_data = ['sample text for vectorization']
        X_new = vectorizer.transform(new_data)
        print(X_new.toarray())

def main():
    data = ['example text for NLP', 'another example for processing']
    X, vectorizer = prepare_data(data)
    process_data(X, vectorizer)
main()