import numpy as np

class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectors = np.zeros((len(data), 100))

    def preprocess(self):
        self.data = [d.lower().split() for d in self.data]

    def transform(self):
        for i, text in enumerate(self.data):
            for word in text:
                if word in self.vocabulary:
                    self.vectors[i] += self.vocabulary[word]

    def fit_transform(self):
        self.preprocess()
        self.build_vocabulary()
        self.transform()
        return self.vectors

    def build_vocabulary(self):
        self.vocabulary = {}
        for text in self.data:
            for word in text:
                if word not in self.vocabulary:
                    self.vocabulary[word] = np.random.rand(100)

def load_data():
    return ['Example sentence one', 'Another example sentence two', 'Yet another example']

def main():
    data = load_data()
    vectorizer = Vectorizer(data)
    vectors = vectorizer.fit_transform()
    print(vectors)
if __name__ == '__main__':
    main()