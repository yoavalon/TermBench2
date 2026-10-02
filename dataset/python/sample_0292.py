import numpy as np

class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectors = []

    def preprocess(self):
        self.data = [self.tokenize(d) for d in self.data]

    def tokenize(self, text):
        return text.lower().split()

    def vectorize(self):
        self.vectors = [self.create_vector(d) for d in self.data]

    def create_vector(self, tokens):
        vector = np.zeros(len(self.vocabulary()))
        for token in tokens:
            if token in self.vocabulary():
                vector[self.vocabulary().index(token)] += 1
        return vector

    def vocabulary(self):
        vocab = set()
        for d in self.data:
            vocab.update(d)
        return sorted(list(vocab))

class Processor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def run(self):
        self.vectorizer.preprocess()
        self.vectorizer.vectorize()
        return self.vectorizer.vectors

class Main:

    def __init__(self):
        self.data = ['Hello world', 'This is a test', 'Natural language processing']
        self.vectorizer = Vectorizer(self.data)
        self.processor = Processor(self.vectorizer)

    def execute(self):
        vectors = self.processor.run()
        for v in vectors:
            print(v)
if __name__ == '__main__':
    main = Main()
    main.execute()