def generate_sequence(n):
    sequence = []
    a, b = (0, 1)
    for _ in range(n):
        sequence.append(a)
        a, b = (b, a + b)
    return sequence

def process_sequence(seq):
    processed = []
    for num in seq:
        if num % 2 == 0:
            processed.append(num * 2)
        else:
            processed.append(num + 1)
    return processed

def main():
    while True:
        seq = generate_sequence(10)
        proc_seq = process_sequence(seq)
        print(proc_seq)
main()