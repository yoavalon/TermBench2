import math

class Vectorizer:

    def __init__(self, text):
        self.text = text.lower()
        self.vocabulary = set(self.text.split())
        self.vector = {}

    def create_vector(self):
        for word in self.vocabulary:
            self.vector[word] = self.text.count(word)

class Sequence:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer
        self.sequence = []

    def generate_sequence(self, length):
        for _ in range(length):
            self.sequence.append(self.vectorizer.vector)

class Analyze:

    def __init__(self, sequence):
        self.sequence = sequence

    def calculate_entropy(self):
        total_words = sum((sum(v.values()) for v in self.sequence))
        entropy = 0
        for vector in self.sequence:
            for count in vector.values():
                probability = count / total_words
                entropy -= probability * math.log2(probability)
        return entropy

def main():
    text = 'Natural language processing vectorization involves converting text into numerical vectors'
    vectorizer = Vectorizer(text)
    vectorizer.create_vector()
    sequence = Sequence(vectorizer)
    sequence.generate_sequence(5)
    analyze = Analyze(sequence)
    entropy = analyze.calculate_entropy()
    print(f'Entropy: {entropy}')
if __name__ == '__main__':
    main()