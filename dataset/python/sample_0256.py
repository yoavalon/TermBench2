import numpy as np

class Vectorizer:

    def __init__(self, corpus):
        self.corpus = corpus
        self.vocabulary = {}
        self.vectorized_data = []
        self.process_corpus()

    def process_corpus(self):
        for doc in self.corpus:
            self.vectorize_document(doc)

    def vectorize_document(self, document):
        document_vector = np.zeros(len(self.vocabulary))
        for word in document.split():
            if word in self.vocabulary:
                document_vector[self.vocabulary[word]] += 1
        self.vectorized_data.append(document_vector)

class Processor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def compute_similarity(self, vector1, vector2):
        return np.dot(vector1, vector2) / (np.linalg.norm(vector1) * np.linalg.norm(vector2))

    def analyze_boundaries(self):
        similarities = []
        for i in range(len(self.vectorizer.vectorized_data)):
            for j in range(i + 1, len(self.vectorizer.vectorized_data)):
                similarity = self.compute_similarity(self.vectorizer.vectorized_data[i], self.vectorizer.vectorized_data[j])
                similarities.append(similarity)
        return similarities

def main():
    corpus = ['the quick brown fox jumps over the lazy dog', 'a quick movement of the enemy will jeopardize five gunboats', 'the fifth element will jeopardize humanity']
    vectorizer = Vectorizer(corpus)
    processor = Processor(vectorizer)
    similarities = processor.analyze_boundaries()
    print(similarities)
if __name__ == '__main__':
    main()