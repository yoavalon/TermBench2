import numpy as np

def tokenize(text):
    words = text.lower().split()
    return words

def vectorize(tokens, vocab):
    vector = np.zeros(len(vocab))
    for token in tokens:
        if token in vocab:
            vector[vocab[token]] += 1
    return vector

def main():
    text = 'hello world hello'
    vocab = {'hello': 0, 'world': 1}
    tokens = tokenize(text)
    vector = vectorize(tokens, vocab)
    print(vector)
main()