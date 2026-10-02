def process_text(data):
    from sklearn.feature_extraction.text import CountVectorizer
    vectorizer = CountVectorizer()
    vectors = vectorizer.fit_transform(data)
    return vectors.toarray()

def main():
    sample_data = ['hello world', 'data processing', 'natural language']
    result = process_text(sample_data)
    print(result)
main()