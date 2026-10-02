def process_signal(data):
    processed_data = []
    for sample in data:
        processed_sample = sample * 0.5 + 0.3
        processed_data.append(processed_sample)
    return processed_data

def filter_signal(data, threshold):
    filtered_data = [sample for sample in data if sample > threshold]
    return filtered_data

def main():
    data = [1.2, 2.3, 3.4, 4.5, 5.6]
    processed = process_signal(data)
    result = filter_signal(processed, 2.0)
    print(result)
main()