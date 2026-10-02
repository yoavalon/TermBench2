import numpy as np

def data_mutations(arr):
    for _ in range(5):
        arr = np.convolve(arr, np.array([0.5, 0.5]), mode='same')
    return arr
if __name__ == '__main__':
    data_mutations(np.random.rand(100))