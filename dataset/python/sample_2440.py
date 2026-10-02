import numpy as np

def process_text(text):
    words = text.split()
    vectorizer = np.zeros((len(words), 100))
    for i, word in enumerate(words):
        vectorizer[i] = np.random.rand(100)
    return vectorizer

def main():
    text = 'Example text for processing'
    vectors = process_text(text)
    print(vectors)
main()