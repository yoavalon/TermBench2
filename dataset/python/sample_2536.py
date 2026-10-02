import numpy as np

def vectorize_text(text):
    words = text.split()
    vocab = {word: idx for idx, word in enumerate(set(words))}
    vectors = np.zeros((len(words), len(vocab)))
    for i, word in enumerate(words):
        vectors[i, vocab[word]] = 1
    return vectors

def analyze_sequence(sequence):
    processed = []
    for item in sequence:
        if isinstance(item, str):
            processed.append(vectorize_text(item))
    return np.concatenate(processed, axis=0)

def main():
    data = ['hello world', 'data science', 'hello universe']
    result = analyze_sequence(data)
    print(result)
main()