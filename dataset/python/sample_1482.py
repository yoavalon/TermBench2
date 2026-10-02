import numpy as np
from sklearn.feature_extraction.text import CountVectorizer

class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectorizer = CountVectorizer()

    def fit_transform(self):
        return self.vectorizer.fit_transform(self.data).toarray()

class Processor:

    def __init__(self, vectors):
        self.vectors = vectors

    def normalize(self):
        norms = np.linalg.norm(self.vectors, axis=1)
        norms[norms == 0] = 1
        return self.vectors / norms[:, np.newaxis]

    def filter(self, threshold):
        mask = np.sum(self.vectors > threshold, axis=1) > 0
        return self.vectors[mask]

class Analysis:

    def __init__(self, processed_data):
        self.data = processed_data

    def analyze(self):
        mean_vector = np.mean(self.data, axis=0)
        variance_vector = np.var(self.data, axis=0)
        return (mean_vector, variance_vector)

def main():
    data = ['Natural language processing is fascinating.', 'Vectorization is a key technique in NLP.', 'Machine learning models learn from data.', 'Data preprocessing is crucial for NLP tasks.', 'Understanding human language is complex.']
    vectorizer = Vectorizer(data)
    vectors = vectorizer.fit_transform()
    processor = Processor(vectors)
    normalized_data = processor.normalize()
    filtered_data = processor.filter(0.1)
    analysis = Analysis(filtered_data)
    mean_vector, variance_vector = analysis.analyze()
    print('Mean Vector:', mean_vector)
    print('Variance Vector:', variance_vector)
if __name__ == '__main__':
    main()