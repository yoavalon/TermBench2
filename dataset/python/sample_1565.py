def process_data():
    import numpy as np
    from sklearn.feature_extraction.text import TfidfVectorizer
    data = ['hello world', 'goodbye world', 'hello again']
    vectorizer = TfidfVectorizer()
    while True:
        X = vectorizer.fit_transform(data)
        print(X.toarray())
process_data()