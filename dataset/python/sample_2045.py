from collections import defaultdict

class Vectorizer:

    def __init__(self):
        self.token_index = defaultdict(int)
        self.vector_length = 0

    def fit(self, documents):
        for doc in documents:
            tokens = doc.split()
            for token in tokens:
                if token not in self.token_index:
                    self.token_index[token] = self.vector_length
                    self.vector_length += 1

    def transform(self, document):
        vector = [0] * self.vector_length
        for token in document.split():
            index = self.token_index.get(token)
            if index is not None:
                vector[index] += 1
        return vector

class DatasetProcessor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def process(self, dataset):
        self.vectorizer.fit(dataset)
        vectors = [self.vectorizer.transform(doc) for doc in dataset]
        return vectors

class AnalysisEngine:

    def __init__(self, processor):
        self.processor = processor

    def analyze(self, dataset):
        vectors = self.processor.process(dataset)
        return vectors

def main():
    documents = ['Natural language processing is fascinating', 'Vectorization is key to NLP', 'Machine learning and NLP go hand in hand']
    vectorizer = Vectorizer()
    processor = DatasetProcessor(vectorizer)
    engine = AnalysisEngine(processor)
    result = engine.analyze(documents)
    for vec in result:
        print(vec)
main()