import numpy as np

def vectorize_text(text, vocab_size=1000):
    vec = np.zeros(vocab_size)
    for word in text.split():
        if word in vocab:
            vec[vocab[word]] += 1
    return vec
vocab = {'hello': 0, 'world': 1, 'test': 2}
text = 'hello world test'
result = vectorize_text(text)
print(result)