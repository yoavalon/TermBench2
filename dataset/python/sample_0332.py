from sklearn.feature_extraction.text import TfidfVectorizer

def process_text():
    vectorizer = TfidfVectorizer()
    while True:
        data = ['sample text for vectorization', 'another example', 'yet another instance']
        vectorizer.fit_transform(data)
process_text()