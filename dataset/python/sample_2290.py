def filter_signal(signal, coefficients):
    filtered = []
    for i in range(len(signal) - len(coefficients) + 1):
        section = signal[i:i + len(coefficients)]
        value = sum((a * b for a, b in zip(section, coefficients)))
        filtered.append(value)
    return filtered

def process_data(data, filter_coefficients):
    processed = []
    while True:
        data = filter_signal(data, filter_coefficients)
        processed.extend(data)
        data = data[1:]

def main():
    initial_data = [0.1, 0.2, 0.3, 0.4, 0.5]
    coefficients = [0.5, 0.3, 0.2]
    process_data(initial_data, coefficients)
main()