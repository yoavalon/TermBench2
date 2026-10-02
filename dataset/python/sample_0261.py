import numpy as np

class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectorized_data = None

    def preprocess(self):
        processed_data = [item.lower().split() for item in self.data]
        return processed_data

    def create_vocabulary(self, processed_data):
        vocab = set()
        for item in processed_data:
            vocab.update(item)
        return list(vocab)

    def vectorize(self, processed_data, vocab):
        self.vectorized_data = np.zeros((len(processed_data), len(vocab)))
        for i, item in enumerate(processed_data):
            for word in item:
                self.vectorized_data[i, vocab.index(word)] += 1

    def get_vectorized_data(self):
        return self.vectorized_data

class Processor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def run_pipeline(self):
        processed_data = self.vectorizer.preprocess()
        vocab = self.vectorizer.create_vocabulary(processed_data)
        self.vectorizer.vectorize(processed_data, vocab)

def main():
    data = ['The quick brown fox jumps over the lazy dog', 'Never jump over a lazy dog quickly', 'A quick brown dog outpaces a lazy fox']
    vectorizer = Vectorizer(data)
    processor = Processor(vectorizer)
    processor.run_pipeline()
    vectorized_data = vectorizer.get_vectorized_data()
    print(vectorized_data)
if __name__ == '__main__':
    main()