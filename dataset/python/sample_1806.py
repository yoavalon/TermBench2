import numpy as np

def process_text(data):
    vectors = np.zeros((len(data), 100), dtype=np.float32)
    for i, text in enumerate(data):
        for j, char in enumerate(text[:100]):
            vectors[i, j] = ord(char) / 255.0
    return vectors
data = ['example text', 'another example']
result = process_text(data)
print(result)