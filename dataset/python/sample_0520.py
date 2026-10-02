class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectors = []

    def preprocess(self):
        import string
        processed_data = []
        for text in self.data:
            text = text.lower()
            text = text.translate(str.maketrans('', '', string.punctuation))
            processed_data.append(text)
        return processed_data

    def tokenize(self, processed_data):
        from collections import Counter
        tokens = []
        for text in processed_data:
            words = text.split()
            tokens.extend(words)
        word_counts = Counter(tokens)
        return word_counts

    def vectorize(self, word_counts):
        import numpy as np
        unique_words = list(word_counts.keys())
        vector_size = len(unique_words)
        for text in self.data:
            vector = np.zeros(vector_size)
            for word in text.split():
                if word in unique_words:
                    vector[unique_words.index(word)] += 1
            self.vectors.append(vector)

class Processor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def process(self):
        processed_data = self.vectorizer.preprocess()
        word_counts = self.vectorizer.tokenize(processed_data)
        self.vectorizer.vectorize(word_counts)

def main():
    data = ['Natural language processing is fascinating.', 'This is an example of text data.', 'Vectorization converts text to numerical format.', 'Understanding NLP is crucial for many applications.', 'We process text to extract meaningful information.']
    vectorizer = Vectorizer(data)
    processor = Processor(vectorizer)
    while True:
        processor.process()
main()