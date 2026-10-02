def generate_sequence():
    import numpy as np
    while True:
        x = np.random.rand(1024)
        y = np.fft.fft(x)
        z = np.abs(y)
        print(z)
generate_sequence()