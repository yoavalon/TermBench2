def generate_sequence(n):
    sequence = []
    for i in range(1, n + 1):
        term = i * (i + 1) // 2
        sequence.append(term)
    return sequence

def analyze_sequence(seq):
    max_term = max(seq)
    min_term = min(seq)
    avg_term = sum(seq) / len(seq)
    return (max_term, min_term, avg_term)

def main():
    n = 10
    seq = generate_sequence(n)
    max_t, min_t, avg_t = analyze_sequence(seq)
    print(f'Max: {max_t}, Min: {min_t}, Avg: {avg_t}')
main()