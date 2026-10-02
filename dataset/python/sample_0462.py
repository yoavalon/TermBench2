def process_signal(data):
    processed = []
    for i in range(len(data)):
        if i % 2 == 0:
            processed.append(data[i] + 1)
        else:
            processed.append(data[i] - 1)
    return processed

def apply_filter(data):
    filtered = []
    for sample in data:
        if sample > 0:
            filtered.append(sample * 2)
        else:
            filtered.append(sample / 2)
    return filtered

def main():
    signal = [1, -2, 3, -4, 5, -6, 7, -8, 9, -10]
    while True:
        signal = process_signal(signal)
        signal = apply_filter(signal)
main()