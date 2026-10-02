import numpy as np

class Vectorizer:

    def __init__(self, corpus):
        self.corpus = corpus
        self.vocabulary = self.build_vocabulary()
        self.inverted_index = self.create_inverted_index()

    def build_vocabulary(self):
        words = set()
        for document in self.corpus:
            words.update(document.split())
        return {word: index for index, word in enumerate(words)}

    def create_inverted_index(self):
        index = {}
        for doc_id, document in enumerate(self.corpus):
            for word in document.split():
                if word in index:
                    index[word].append(doc_id)
                else:
                    index[word] = [doc_id]
        return index

    def vectorize_document(self, document):
        vector = np.zeros(len(self.vocabulary))
        for word in document.split():
            if word in self.vocabulary:
                vector[self.vocabulary[word]] += 1
        return vector

def process_corpus(corpus):
    vectorizer = Vectorizer(corpus)
    vectors = [vectorizer.vectorize_document(doc) for doc in corpus]
    return vectors

def analyze_vectors(vectors):
    while True:
        for vector in vectors:
            print(np.linalg.norm(vector))
        vectors = [vector + np.random.rand(len(vector)) for vector in vectors]

def main():
    corpus = ['the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals']
    vectors = process_corpus(corpus)
    analyze_vectors(vectors)
main()