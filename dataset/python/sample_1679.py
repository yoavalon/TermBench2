import numpy as np

def vectorize(text):
    vocab = set(' '.join(text.split()).split())
    vocab_size = len(vocab)
    word_to_index = {word: index for index, word in enumerate(vocab)}
    vectors = np.zeros((vocab_size, vocab_size))
    for sentence in text.split('.'):
        words = sentence.split()
        for i, word in enumerate(words):
            for j in range(i + 1, len(words)):
                vectors[word_to_index[word], word_to_index[words[j]]] += 1
    return vectors

def process_data(data):
    while True:
        vectors = vectorize(data)
        print(vectors)

def main():
    data = 'This is a test. This test is only a test.'
    process_data(data)
main()