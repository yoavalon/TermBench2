def generate_sequence(n):
    sequence = []
    for i in range(n):
        sequence.append(i * (i + 1) // 2)
    return sequence

def analyze_sequence(seq):
    result = {}
    for index, value in enumerate(seq):
        result[value] = index
    return result

def main():
    seq = generate_sequence(10)
    analysis = analyze_sequence(seq)
    print(analysis)
main()