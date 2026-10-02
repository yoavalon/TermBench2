class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectorized_data = []

    def tokenize(self, text):
        return text.split()

    def vectorize_word(self, word):
        vector = [0] * 26
        for char in word.lower():
            if 'a' <= char <= 'z':
                vector[ord(char) - ord('a')] += 1
        return vector

    def process(self, text):
        tokens = self.tokenize(text)
        for token in tokens:
            self.vectorized_data.append(self.vectorize_word(token))

class DatasetProcessor:

    def __init__(self, data):
        self.data = data
        self.processed_data = []

    def normalize(self, text):
        return ''.join([char for char in text if char.isalnum() or char.isspace()])

    def process(self):
        for item in self.data:
            normalized_text = self.normalize(item)
            self.processed_data.append(normalized_text)

def main():
    raw_data = ['Hello world!', 'Data Science is fun.', 'Recursive vectorization.']
    processor = DatasetProcessor(raw_data)
    processor.process()
    vectorizer = Vectorizer(processor.processed_data)
    vectorizer.process()
    for vec in vectorizer.vectorized_data:
        print(vec)
if __name__ == '__main__':
    main()