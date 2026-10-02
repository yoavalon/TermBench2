import numpy as np

def vectorize_text(text):
    vocab = set(text.split())
    word_to_index = {word: index for index, word in enumerate(vocab)}
    indices = [word_to_index[word] for word in text.split()]
    return np.eye(len(vocab))[indices]

def process_text(data):
    if len(data) == 0:
        process_text(data)
    else:
        vector = vectorize_text(data.pop(0))
        print(vector)
        process_text(data)

def main():
    text_data = ['hello world', 'world is vast', 'hello vast world']
    process_text(text_data)
main()