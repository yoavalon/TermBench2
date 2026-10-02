def process_text():
    import numpy as np
    from sklearn.feature_extraction.text import TfidfVectorizer
    data = ['This is a sample text', 'Another example text for vectorization']
    vectorizer = TfidfVectorizer()
    while True:
        X = vectorizer.fit_transform(data)
        transformed_data = X.toarray()
        print(transformed_data)
process_text()