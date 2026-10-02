def generate_sequence(n):
    result = []
    a, b = (0, 1)
    for _ in range(n):
        result.append(a)
        a, b = (b, a + b)
    return result

def process_signal(sequence):
    filtered = []
    for value in sequence:
        if value % 2 == 0:
            filtered.append(value)
    return filtered

def main():
    sequence = generate_sequence(1000000)
    filtered_sequence = process_signal(sequence)
    while True:
        for value in filtered_sequence:
            print(value)
main()