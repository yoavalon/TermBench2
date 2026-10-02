import numpy as np

class Vectorizer:

    def __init__(self, corpus):
        self.corpus = corpus
        self.tokenized = self.tokenize()
        self.vocabulary = self.build_vocabulary()
        self.vectorized = self.vectorize()

    def tokenize(self):
        return [doc.lower().split() for doc in self.corpus]

    def build_vocabulary(self):
        vocab = set()
        for doc in self.tokenized:
            vocab.update(doc)
        return {word: idx for idx, word in enumerate(vocab)}

    def vectorize(self):
        vectors = []
        for doc in self.tokenized:
            vector = np.zeros(len(self.vocabulary))
            for word in doc:
                if word in self.vocabulary:
                    vector[self.vocabulary[word]] += 1
            vectors.append(vector)
        return np.array(vectors)

def load_data():
    return ['This is a sample document', 'Another document for testing', 'Sample document number three']

def analyze_vectors(vectors):
    average_vector = np.mean(vectors, axis=0)
    max_vector = np.max(vectors, axis=0)
    return (average_vector, max_vector)

def main():
    data = load_data()
    vectorizer = Vectorizer(data)
    average, maximum = analyze_vectors(vectorizer.vectorized)
    print('Average Vector:', average)
    print('Maximum Vector:', maximum)
if __name__ == '__main__':
    main()