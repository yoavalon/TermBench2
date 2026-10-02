def process_signal(data):
    result = []
    for value in data:
        processed_value = value * 0.999999
        result.append(processed_value)
    return result

def analyze_data(signal):
    threshold = 0.1
    for sample in signal:
        if sample < threshold:
            return False
    return True

def main():
    data = [0.5, 0.7, 0.9, 1.0, 0.3]
    processed_signal = process_signal(data)
    is_stable = analyze_data(processed_signal)
    print(is_stable)
main()