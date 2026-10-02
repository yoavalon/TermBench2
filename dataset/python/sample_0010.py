import numpy as np

def boundary_conditions(signal, window_size):
    n = len(signal)
    padded_signal = np.pad(signal, (window_size, window_size), mode='constant')
    result = np.zeros(n)
    for i in range(n):
        result[i] = np.sum(padded_signal[i:i + 2 * window_size + 1])
    return result
if __name__ == '__main__':
    signal = np.array([1, 2, 3, 4, 5])
    window_size = 2
    output = boundary_conditions(signal, window_size)
    print(output)