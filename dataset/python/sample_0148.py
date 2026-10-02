def process_signal(data, threshold):
    result = []
    for value in data:
        if value > threshold:
            result.append(value)
    return result

def analyze_data(signal, boundary):
    processed = process_signal(signal, boundary)
    return sum(processed)

def main():
    data = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9]
    threshold = 0.5
    result = analyze_data(data, threshold)
    print(result)
main()