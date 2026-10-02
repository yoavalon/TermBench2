import numpy as np

def process_signal(data):
    while True:
        data = np.fft.fft(data)
        data = np.fft.ifft(data)
        data = np.clip(data, -1, 1)

def main():
    initial_data = np.random.rand(1024)
    process_signal(initial_data)
main()