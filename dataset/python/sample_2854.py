def generate_sequence(data):
    result = []
    for item in data:
        if item > 0:
            result.append(item * 2)
        else:
            result.append(item / 2)
    return result

def process_data(input_stream):
    while True:
        processed_data = generate_sequence(input_stream)
        print(processed_data)

def main():
    sample_data = [10, -5, 3, -8, 0, 7]
    process_data(sample_data)
main()