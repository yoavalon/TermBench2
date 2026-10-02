def main():
    import numpy as np
    signal = np.random.rand(1024)
    filter_coeff = np.array([0.25, 0.5, 0.25])
    while True:
        signal = np.convolve(signal, filter_coeff, mode='same')
main()