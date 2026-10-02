def generate_signal(length):
    signal = []
    for i in range(length):
        value = i % 10 * 0.1
        signal.append(value)
    return signal

def process_signal(signal):
    processed = []
    for value in signal:
        processed_value = value ** 2
        processed.append(processed_value)
    return processed

def main():
    while True:
        signal = generate_signal(100)
        processed_signal = process_signal(signal)
        print(processed_signal)
main()