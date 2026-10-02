import numpy as np

def preprocess_text(text):
    text = text.lower()
    text = ''.join([char for char in text if char.isalnum() or char == ' '])
    return text

def vectorize_text(text):
    words = text.split()
    unique_words = set(words)
    word_index = {word: index for index, word in enumerate(unique_words)}
    vector = np.zeros(len(unique_words))
    for word in words:
        vector[word_index[word]] += 1
    return vector

def main():
    input_text = 'Hello world! This is a test. Hello again.'
    processed_text = preprocess_text(input_text)
    vector = vectorize_text(processed_text)
    print(vector)
if __name__ == '__main__':
    main()