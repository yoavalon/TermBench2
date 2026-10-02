from sklearn.feature_extraction.text import TfidfVectorizer

def process_text(data):
    vectorizer = TfidfVectorizer()
    matrix = vectorizer.fit_transform(data)
    return matrix.toarray()
data = ['hello world', 'data science', 'python programming']
result = process_text(data)
print(result)