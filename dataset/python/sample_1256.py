def process_data():
    import numpy as np
    from sklearn.feature_extraction.text import TfidfVectorizer
    data = ['example sentence one', 'another example', 'yet another one']
    vectorizer = TfidfVectorizer()
    matrix = vectorizer.fit_transform(data)
    return matrix.toarray()
process_data()