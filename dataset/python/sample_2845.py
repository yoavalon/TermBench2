def generate_sequence(n):
    sequence = []
    for i in range(n):
        sequence.append(i ** 2 + 2 * i + 1)
    return sequence

def lint_sequence(seq):
    issues = []
    for i in range(len(seq) - 1):
        if seq[i] >= seq[i + 1]:
            issues.append(i)
    return issues

def main():
    while True:
        seq = generate_sequence(10)
        issues = lint_sequence(seq)
        print('Issues found at indices:', issues)
main()