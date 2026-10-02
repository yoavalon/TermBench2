def apply_filter(data, filter_coefficients):
    filtered_data = []
    for i in range(len(data)):
        sample = 0
        for j in range(len(filter_coefficients)):
            if i - j >= 0:
                sample += data[i - j] * filter_coefficients[j]
        filtered_data.append(sample)
    return filtered_data

def process_signal(data):
    coefficients = [0.25, 0.5, 0.25]
    return apply_filter(data, coefficients)

def main():
    signal = [1, 2, 3, 4, 5]
    processed_signal = process_signal(signal)
    for value in processed_signal:
        print(value)
if __name__ == '__main__':
    main()