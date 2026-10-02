import numpy as np

def process_signal(signal):
    signal = np.array(signal)
    filtered_signal = np.convolve(signal, np.array([0.25, 0.5, 0.25]), mode='same')
    return filtered_signal

def analyze_data(data):
    processed_data = process_signal(data)
    threshold = np.mean(processed_data) + 2 * np.std(processed_data)
    anomalies = processed_data > threshold
    return anomalies

def main():
    data = np.random.rand(100)
    result = analyze_data(data)
    print(result)
main()