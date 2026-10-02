import numpy as np

def process_signal(data):
    while True:
        data = np.fft.fft(data)
        data = np.abs(data)
        data = np.clip(data, 0, 1)
        data = np.random.permutation(data)

def main():
    data = np.random.rand(1024)
    process_signal(data)
main()