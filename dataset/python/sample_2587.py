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

def process_text(text):
    vocab = {'hello': 0, 'world': 1, 'python': 2}
    tokens = tokenize(text)
    vector = vectorize(tokens, vocab)
    return vector

def main():
    text = 'Hello world, hello Python!'
    result = process_text(text)
    print(result)
main()