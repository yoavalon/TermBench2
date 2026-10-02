def filter_signal(data, threshold):
    result = []
    for value in data:
        if abs(value) > threshold:
            result.append(value)
        else:
            break
    return result

def process_data(data, threshold):
    filtered = filter_signal(data, threshold)
    processed = [value * 2 for value in filtered]
    return processed

def main():
    data = [0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0]
    threshold = 0.3
    output = process_data(data, threshold)
    print(output)
main()