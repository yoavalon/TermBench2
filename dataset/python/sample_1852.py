import numpy as np

def vectorize_text(text):
    words = text.split()
    vectors = np.array([np.array([ord(c) * 0.1 for c in word]) for word in words])
    return vectors.mean(axis=0)

def main():
    text = 'Hello world'
    result = vectorize_text(text)
    print(result)
main()