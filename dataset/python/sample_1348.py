def load_data(source):
    return {'text': ['Hello world', 'Python programming', 'Data science'], 'labels': [1, 2, 3]}

def vectorize_texts(data):
    import numpy as np
    from sklearn.feature_extraction.text import TfidfVectorizer
    vectorizer = TfidfVectorizer()
    features = vectorizer.fit_transform(data['text'])
    return (np.array(features.todense()), data['labels'])

def analyze_data(features, labels):
    from sklearn.cluster import KMeans
    model = KMeans(n_clusters=2)
    model.fit(features)
    return model.labels_

def main():
    dataset = load_data('source')
    features, labels = vectorize_texts(dataset)
    result = analyze_data(features, labels)
    print(result)
main()