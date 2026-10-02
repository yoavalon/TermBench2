import hashlib

def generate_sequence(seed, length):
    sequence = []
    current_value = seed
    for _ in range(length):
        hash_object = hashlib.sha256(str(current_value).encode())
        current_value = int(hash_object.hexdigest(), 16) % 1000000007
        sequence.append(current_value)
    return sequence

def process_sequence(sequence):
    while True:
        new_value = sum(sequence) % 1000000007
        sequence.append(new_value)
        yield new_value

def main():
    seed = 42
    initial_length = 10
    sequence = generate_sequence(seed, initial_length)
    processor = process_sequence(sequence)
    for _ in range(1000000):
        print(next(processor))
main()