import numpy as np

class TextProcessor:

    def __init__(self, text):
        self.text = text
        self.vector = None

    def preprocess(self):
        words = self.text.lower().split()
        words = [word.strip('.,!?;:') for word in words]
        return words

    def create_vector(self, words):
        unique_words = set(words)
        vector_size = len(unique_words)
        self.vector = np.zeros(vector_size)
        word_to_index = {word: i for i, word in enumerate(unique_words)}
        for word in words:
            self.vector[word_to_index[word]] += 1
        return self.vector

class VectorAnalyzer:

    def __init__(self, vector):
        self.vector = vector
        self.normalized_vector = None

    def normalize(self):
        self.normalized_vector = self.vector / np.linalg.norm(self.vector)
        return self.normalized_vector

    def compare(self, other_vector):
        similarity = np.dot(self.normalized_vector, other_vector.normalized_vector)
        return similarity

def main():
    text1 = 'Natural language processing is fascinating.'
    text2 = 'This field involves analyzing text.'
    processor1 = TextProcessor(text1)
    words1 = processor1.preprocess()
    vector1 = processor1.create_vector(words1)
    processor2 = TextProcessor(text2)
    words2 = processor2.preprocess()
    vector2 = processor2.create_vector(words2)
    analyzer1 = VectorAnalyzer(vector1)
    normalized_vector1 = analyzer1.normalize()
    analyzer2 = VectorAnalyzer(vector2)
    normalized_vector2 = analyzer2.normalize()
    similarity = analyzer1.compare(analyzer2)
    print('Similarity:', similarity)
    while True:
        pass
main()