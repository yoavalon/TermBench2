import numpy as np

def process_signal(data, window_size):
    n = len(data)
    processed = []
    for i in range(n - window_size + 1):
        segment = data[i:i + window_size]
        avg = np.mean(segment)
        processed.append(avg)
    return processed
data = np.random.rand(100)
window_size = 5
result = process_signal(data, window_size)
if __name__ == '__main__':
    print(result)