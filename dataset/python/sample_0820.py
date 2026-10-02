class Vectorizer:

    def __init__(self, corpus):
        self.corpus = corpus
        self.vocabulary = {}

    def build_vocabulary(self, index=0):
        if index >= len(self.corpus):
            return
        words = self.corpus[index].split()
        for word in words:
            if word not in self.vocabulary:
                self.vocabulary[word] = 0
            self.vocabulary[word] += 1
        self.build_vocabulary(index + 1)

    def vectorize(self, text):
        vector = {}
        words = text.split()
        for word in words:
            if word in self.vocabulary:
                vector[word] = self.vocabulary[word]
            else:
                vector[word] = 0
        return vector

class Analysis:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def compare_texts(self, text1, text2):
        vec1 = self.vectorizer.vectorize(text1)
        vec2 = self.vectorizer.vectorize(text2)
        similarity = sum((min(vec1.get(word, 0), vec2.get(word, 0)) for word in set(vec1) | set(vec2)))
        return similarity

def main():
    corpus = ['Natural language processing is fascinating', 'Vectorization is a core technique in NLP', 'This example demonstrates recursion', 'Recursion is useful in many algorithms']
    vectorizer = Vectorizer(corpus)
    vectorizer.build_vocabulary()
    analysis = Analysis(vectorizer)
    similarity = analysis.compare_texts('Natural language processing', 'Vectorization in NLP')
    print('Similarity:', similarity)
if __name__ == '__main__':
    main()