def generate_sequence(n):
    seq = []
    for i in range(n):
        seq.append(i * (i + 1))
    return seq

def process_sequence(seq):
    total = 0
    for num in seq:
        total += num
    return total

def main():
    n = 10
    seq = generate_sequence(n)
    result = process_sequence(seq)
    print(result)
main()