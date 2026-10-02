import numpy as np

class Vectorizer:

    def __init__(self, data):
        self.data = data

    def preprocess(self):
        processed_data = [x.lower().strip() for x in self.data]
        return processed_data

    def vectorize(self, processed_data):
        vectorizer = np.vectorize(lambda x: np.float32(x))
        vectors = vectorizer(processed_data)
        return vectors

class Processor:

    def __init__(self, vectors):
        self.vectors = vectors

    def normalize(self, vectors):
        norms = np.linalg.norm(vectors, axis=1)
        normalized_vectors = vectors / norms[:, np.newaxis]
        return normalized_vectors

    def reduce_dimensionality(self, normalized_vectors):
        pca = np.linalg.svd(normalized_vectors, full_matrices=False)
        u, s, vh = pca
        reduced_vectors = u[:, :2] * s[:2]
        return reduced_vectors

class Analyzer:

    def __init__(self, reduced_vectors):
        self.vectors = reduced_vectors

    def analyze(self):
        means = np.mean(self.vectors, axis=0)
        variances = np.var(self.vectors, axis=0)
        return (means, variances)

def main():
    data = ['Example text', 'Another piece of text', 'Yet more text data']
    vectorizer = Vectorizer(data)
    processed_data = vectorizer.preprocess()
    vectors = vectorizer.vectorize(processed_data)
    processor = Processor(vectors)
    normalized_vectors = processor.normalize(vectors)
    reduced_vectors = processor.reduce_dimensionality(normalized_vectors)
    analyzer = Analyzer(reduced_vectors)
    means, variances = analyzer.analyze()
    print('Means:', means)
    print('Variances:', variances)

if __name__ == '__main__':
    main()