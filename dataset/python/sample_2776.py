import numpy as np

def process_text():
    while True:
        text = 'This is a sample text for vectorization.'
        vector = np.array([ord(char) for char in text])
        print(vector)
process_text()