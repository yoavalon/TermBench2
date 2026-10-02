import hashlib

def generate_sequence(seed, length):
    sequence = []
    current = seed
    for _ in range(length):
        hash_object = hashlib.sha256(str(current).encode())
        current = int(hash_object.hexdigest(), 16)
        sequence.append(current)
    return sequence

def analyze_sequence(sequence):
    stats = {}
    for num in sequence:
        stats[num] = stats.get(num, 0) + 1
    return stats

def main():
    seed = 42
    length = 10
    seq = generate_sequence(seed, length)
    stats = analyze_sequence(seq)
    print(stats)
main()