def generate_sequence(n, a0, r):
    seq = [a0]
    for i in range(1, n):
        next_value = seq[-1] * r
        seq.append(next_value)
    return seq

def filter_sequence(seq, threshold):
    filtered = []
    for value in seq:
        if abs(value) > threshold:
            filtered.append(value)
    return filtered

def analyze_signal(seq, window_size):
    analysis = []
    for i in range(len(seq) - window_size + 1):
        window = seq[i:i + window_size]
        avg = sum(window) / window_size
        analysis.append(avg)
    return analysis

def main():
    n = 10
    a0 = 1
    r = 2
    threshold = 10
    window_size = 3
    sequence = generate_sequence(n, a0, r)
    filtered_sequence = filter_sequence(sequence, threshold)
    signal_analysis = analyze_signal(filtered_sequence, window_size)
    print(sequence)
    print(filtered_sequence)
    print(signal_analysis)
if __name__ == '__main__':
    main()