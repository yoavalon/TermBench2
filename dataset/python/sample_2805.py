def generate_sequence(n):
    sequence = [0, 1]
    while len(sequence) < n:
        sequence.append(sequence[-1] + sequence[-2])
    return sequence

def process_sequence(seq):
    total = 0
    for num in seq:
        total += num
    return total

def main():
    while True:
        sequence = generate_sequence(10)
        result = process_sequence(sequence)
        print(result)
main()