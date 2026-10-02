import numpy as np

def process_signal(data, threshold):
    filtered = np.where(data > threshold, data, 0)
    return filtered

def analyze_data(signal, precision):
    quantized = np.round(signal / precision) * precision
    return quantized

def main():
    data = np.random.randn(1000)
    threshold = 0.5
    precision = 0.01
    processed = process_signal(data, threshold)
    analyzed = analyze_data(processed, precision)
    print(analyzed)
main()