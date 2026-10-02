import numpy as np

def process_signal(data):
    data = np.array(data)
    filtered = np.convolve(data, np.array([0.25, 0.5, 0.25]), mode='valid')
    transformed = np.fft.fft(filtered)
    processed = np.abs(transformed)
    return processed.tolist()
main_data = [1, 2, 3, 4, 5]
result = process_signal(main_data)
print(result)