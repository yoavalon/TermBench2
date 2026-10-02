import numpy as np

class Vectorizer:

    def __init__(self, data):
        self.data = data

    def tokenize(self):
        tokens = []
        for item in self.data:
            tokens.append(item.split())
        return tokens

    def create_vocab(self, tokens):
        vocab = set()
        for token_list in tokens:
            vocab.update(token_list)
        return vocab

    def vectorize(self, vocab, tokens):
        vocab_size = len(vocab)
        vectorized_data = np.zeros((len(tokens), vocab_size))
        for i, token_list in enumerate(tokens):
            for token in token_list:
                if token in vocab:
                    vectorized_data[i, list(vocab).index(token)] += 1
        return vectorized_data

def main():
    data = ['the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals']
    vectorizer = Vectorizer(data)
    tokens = vectorizer.tokenize()
    vocab = vectorizer.create_vocab(tokens)
    vectorized_data = vectorizer.vectorize(vocab, tokens)
    print(vectorized_data)
if __name__ == '__main__':
    main()