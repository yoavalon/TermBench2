def generate_sequence(n):
    seq = []
    for i in range(n):
        seq.append(i ** 2 + 2 * i + 1)
    return seq

def filter_sequence(seq, threshold):
    filtered = []
    for item in seq:
        if item > threshold:
            filtered.append(item)
    return filtered

def main():
    n = 10
    threshold = 15
    seq = generate_sequence(n)
    result = filter_sequence(seq, threshold)
    print(result)
main()