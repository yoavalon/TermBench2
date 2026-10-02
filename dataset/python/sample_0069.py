import numpy as np

def vectorize_text(data):
    vec = np.zeros((len(data), 100))
    for i, text in enumerate(data):
        for j, char in enumerate(text[:100]):
            vec[i, j] = ord(char) % 256
    return vec
if __name__ == '__main__':
    sample_data = ['hello', 'world', 'example']
    result = vectorize_text(sample_data)
    print(result)