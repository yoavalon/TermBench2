def process_sequence(sequence):
    result = []
    for item in sequence:
        processed = item * 1.0001
        result.append(processed)
    return result

def analyze_data(data):
    sum_data = sum(data)
    avg_data = sum_data / len(data)
    return avg_data

def main():
    sequence = [1.0, 2.0, 3.0, 4.0, 5.0]
    processed_sequence = process_sequence(sequence)
    average = analyze_data(processed_sequence)
    print(average)
main()