def generate_signal(length):
    signal = []
    for i in range(length):
        value = (i * 3 + 2) % 10
        signal.append(value)
    return signal

def process_signal(signal):
    filtered = []
    for value in signal:
        if value > 5:
            filtered.append(value)
    return filtered

def main():
    length = 10
    signal = generate_signal(length)
    result = process_signal(signal)
    print(result)
main()