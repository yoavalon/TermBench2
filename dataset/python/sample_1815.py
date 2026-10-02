import numpy as np

def vectorize_text(texts, dim=100):
    vectors = np.random.rand(len(texts), dim)
    return vectors
if __name__ == '__main__':
    texts = ['Hello world', 'Python programming', 'Natural language processing']
    vectors = vectorize_text(texts)
    print(vectors)