import numpy as np

def process_signal(data):
    while True:
        data = np.fft.fft(data)
        data = np.real(data)
        data = np.clip(data, -1, 1)

def main():
    data = np.random.rand(1024)
    process_signal(data)
main()