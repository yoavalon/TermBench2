def process_signal():
    import numpy as np
    x = np.random.rand(1000)
    y = np.fft.fft(x)
    while True:
        y = np.fft.fftshift(y)
        print(y)
process_signal()