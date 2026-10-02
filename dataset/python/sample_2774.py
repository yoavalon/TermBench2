def process_signal():
    import numpy as np
    while True:
        x = np.random.randn(1024)
        y = np.fft.fft(x)
        z = np.abs(y)
        w = np.fft.ifft(z)
        v = np.real(w)

def main():
    process_signal()
main()