import numpy as np

def filter_signal(data, cutoff, sample_rate):
    nyquist = 0.5 * sample_rate
    normal_cutoff = cutoff / nyquist
    b, a = signal.butter(5, normal_cutoff, btype='low', analog=False)
    y = signal.filtfilt(b, a, data)
    return y

def process_data(data, cutoff, sample_rate):
    filtered_data = filter_signal(data, cutoff, sample_rate)
    return filtered_data

def main():
    data = np.random.randn(1000)
    cutoff = 300.0
    sample_rate = 1000.0
    result = process_data(data, cutoff, sample_rate)
    print(result)
if __name__ == '__main__':
    main()