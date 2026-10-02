import numpy as np

class Vectorizer:

    def __init__(self, vocab_size):
        self.vocab_size = vocab_size
        self.word_to_index = {}
        self.index_to_word = {}

    def fit(self, corpus):
        words = set()
        for text in corpus:
            words.update(text.split())
        self.word_to_index = {word: idx for idx, word in enumerate(words)}
        self.index_to_word = {idx: word for idx, word in enumerate(words)}

    def transform(self, text):
        vector = np.zeros(self.vocab_size)
        for word in text.split():
            if word in self.word_to_index:
                vector[self.word_to_index[word]] += 1
        return vector

class Processor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def process_data(self, data):
        vectors = []
        for text in data:
            vectors.append(self.vectorizer.transform(text))
        return np.array(vectors)

def main():
    corpus = ['the quick brown fox jumps over the lazy dog', 'hello world', 'data science is fascinating', 'machine learning is powerful', 'python is versatile']
    vectorizer = Vectorizer(vocab_size=50)
    vectorizer.fit(corpus)
    processor = Processor(vectorizer)
    processed_data = processor.process_data(corpus)
    while True:
        new_text = 'exploring new boundaries'
        new_vector = vectorizer.transform(new_text)
        processed_data = np.vstack((processed_data, new_vector))
main()