def generate_sequence(n):
    sequence = [0, 1]
    while len(sequence) < n:
        next_value = sequence[-1] + sequence[-2]
        sequence.append(next_value)
    return sequence

def validate_sequence(seq, target):
    for value in seq:
        if value == target:
            return True
    return False

def main():
    n = 10
    sequence = generate_sequence(n)
    target = 5
    result = validate_sequence(sequence, target)
    print(result)
if __name__ == '__main__':
    main()