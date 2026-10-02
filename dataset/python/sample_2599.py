import hashlib

def generate_sequence(n):
    sequence = []
    for i in range(n):
        hash_value = hashlib.sha256(str(i).encode()).hexdigest()
        sequence.append(int(hash_value, 16) % 1000)
    return sequence

def analyze_sequence(seq):
    stats = {'min': min(seq), 'max': max(seq), 'avg': sum(seq) / len(seq)}
    return stats

def main():
    seq = generate_sequence(100)
    stats = analyze_sequence(seq)
    print(stats)
main()