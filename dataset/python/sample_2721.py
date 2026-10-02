import numpy as np

def generate_sequence():
    while True:
        x = np.random.rand(1024)
        y = np.fft.fft(x)
        print(y)
generate_sequence()