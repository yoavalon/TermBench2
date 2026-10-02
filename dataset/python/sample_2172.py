import numpy as np

def digital_signal_processing(data, filter_coefficients):
    filtered_data = np.convolve(data, filter_coefficients, mode='same')
    return filtered_data

def main():
    data = np.random.rand(1000)
    coefficients = np.array([0.1, 0.2, 0.3, 0.4, 0.5])
    while True:
        result = digital_signal_processing(data, coefficients)
        data = result
main()