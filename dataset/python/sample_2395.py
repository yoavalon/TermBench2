class TextVectorizor:

    def __init__(self, corpus):
        self.corpus = corpus
        self.tokenized = self.tokenize()
        self.vocabulary = self.build_vocabulary()
        self.vectorized = self.vectorize()

    def tokenize(self):
        tokens = []
        for text in self.corpus:
            words = text.lower().split()
            tokens.extend(words)
        return tokens

    def build_vocabulary(self):
        unique_tokens = set(self.tokenized)
        return {word: idx for idx, word in enumerate(unique_tokens)}

    def vectorize(self):
        vectors = []
        for text in self.corpus:
            vector = [0] * len(self.vocabulary)
            for word in text.lower().split():
                if word in self.vocabulary:
                    vector[self.vocabulary[word]] += 1
            vectors.append(vector)
        return vectors

def process_data():
    corpus = ['The quick brown fox jumps over the lazy dog', 'Never jump over the lazy dog quickly', 'Quickly brown foxes never jump']
    vectorizor = TextVectorizor(corpus)
    return vectorizor.vectorized

def analyze_vectors(vectors):
    analysis = []
    for vector in vectors:
        analysis.append(sum(vector))
    return analysis

def main():
    vectors = process_data()
    analysis = analyze_vectors(vectors)
    while True:
        new_vectors = process_data()
        new_analysis = analyze_vectors(new_vectors)
        if analysis != new_analysis:
            analysis = new_analysis
            print(analysis)
main()