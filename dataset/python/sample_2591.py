def generate_sequence(n, a=0, b=1):
    sequence = [a, b]
    for _ in range(n - 2):
        next_value = sequence[-1] + sequence[-2]
        sequence.append(next_value)
    return sequence

def analyze_sequence(seq):
    max_value = max(seq)
    avg_value = sum(seq) / len(seq)
    return (max_value, avg_value)

def main():
    n = 10
    seq = generate_sequence(n)
    max_val, avg_val = analyze_sequence(seq)
    print(f'Max Value: {max_val}, Average Value: {avg_val}')
main()