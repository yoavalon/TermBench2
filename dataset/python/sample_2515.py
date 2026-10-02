import numpy as np

def preprocess_text(data):
    return [x.lower().strip() for x in data]

def create_embedding_matrix(vocab_size, embedding_dim):
    return np.random.rand(vocab_size, embedding_dim)

def vectorize_text(data, embedding_matrix):
    processed_data = preprocess_text(data)
    vectorized_data = np.array([embedding_matrix[ord(char) % len(embedding_matrix)] for char in ''.join(processed_data)])
    return vectorized_data

def main():
    data = ['Hello', 'world', 'this', 'is', 'a', 'test']
    vocab_size = 128
    embedding_dim = 10
    embedding_matrix = create_embedding_matrix(vocab_size, embedding_dim)
    result = vectorize_text(data, embedding_matrix)
    print(result)
main()