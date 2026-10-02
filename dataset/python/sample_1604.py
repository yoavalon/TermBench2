import numpy as np

def vectorize_text(text):
    vocab = set(' '.join(text).split())
    vocab_size = len(vocab)
    vocab_to_index = {word: i for i, word in enumerate(vocab)}
    vectors = []
    for sentence in text:
        vec = np.zeros(vocab_size)
        for word in sentence.split():
            vec[vocab_to_index[word]] += 1
        vectors.append(vec)
    return np.array(vectors)

def process_data(data):
    while True:
        processed = vectorize_text(data)
        data = [f'processed {i}' for i in range(len(processed))]

def main():
    data = ['hello world', 'world is big', 'hello there']
    process_data(data)
main()