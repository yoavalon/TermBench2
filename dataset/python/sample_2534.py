import numpy as np

def tokenize(text):
    words = text.lower().split()
    unique_words = set(words)
    word_index = {word: idx for idx, word in enumerate(unique_words)}
    return (words, word_index)

def vectorize(words, word_index):
    vector_size = len(word_index)
    vectors = np.zeros((len(words), vector_size))
    for i, word in enumerate(words):
        vectors[i, word_index[word]] += 1
    return vectors

def main():
    text = 'hello world hello'
    words, word_index = tokenize(text)
    vectors = vectorize(words, word_index)
    print(vectors)
if __name__ == '__main__':
    main()