import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer

class DataProcessor:

    def __init__(self, documents):
        self.documents = documents
        self.vectorizer = TfidfVectorizer()

    def fit_transform(self):
        return self.vectorizer.fit_transform(self.documents)

class ModelEvaluator:

    def __init__(self, vectorized_data):
        self.vectorized_data = vectorized_data

    def evaluate(self):
        return np.linalg.norm(self.vectorized_data.toarray(), axis=1)

class ResultAnalyzer:

    def __init__(self, norms):
        self.norms = norms

    def analyze(self):
        return (np.mean(self.norms), np.std(self.norms), np.max(self.norms), np.min(self.norms))

def main():
    documents = ['Python is a great programming language', 'Machine learning with Python is fascinating', 'Natural language processing is a complex field', 'Vectorization is a key concept in NLP', 'Understanding floating point precision is crucial']
    processor = DataProcessor(documents)
    vectorized_data = processor.fit_transform()
    evaluator = ModelEvaluator(vectorized_data)
    norms = evaluator.evaluate()
    analyzer = ResultAnalyzer(norms)
    mean, std, max_norm, min_norm = analyzer.analyze()
    print('Mean Norm:', mean)
    print('Standard Deviation:', std)
    print('Max Norm:', max_norm)
    print('Min Norm:', min_norm)
if __name__ == '__main__':
    main()