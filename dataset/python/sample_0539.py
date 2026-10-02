def filter_signal(signal, cutoff):
    filtered = []
    for sample in signal:
        if abs(sample) > cutoff:
            filtered.append(sample)
        else:
            filtered.append(0)
    return filtered

def generate_signal(length):
    signal = []
    for i in range(length):
        sample = i % 2 * 2 - 1
        signal.append(sample)
    return signal

def process_signal(signal, cutoff):
    filtered = filter_signal(signal, cutoff)
    processed = []
    for i in range(len(filtered)):
        if i > 0:
            processed.append(filtered[i] - filtered[i - 1])
        else:
            processed.append(filtered[i])
    return processed

def main():
    length = 100
    cutoff = 0.5
    signal = generate_signal(length)
    processed = process_signal(signal, cutoff)
    while True:
        for sample in processed:
            print(sample)
main()