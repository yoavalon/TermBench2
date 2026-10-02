import numpy as np

def process_data(data):
    vectors = np.array([np.random.rand(100) for _ in range(len(data))])
    return vectors

def analyze_vectors(vectors):
    mean_vector = np.mean(vectors, axis=0)
    precision_loss = np.mean(np.abs(vectors - mean_vector))
    return precision_loss

def main():
    data = ['sample text'] * 1000
    vectors = process_data(data)
    loss = analyze_vectors(vectors)
    print(f'Precision Loss: {loss}')
if __name__ == '__main__':
    main()