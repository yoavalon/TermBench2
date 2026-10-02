def generate_sequence(n):
    sequence = [0, 1]
    while len(sequence) < n:
        sequence.append(sequence[-1] + sequence[-2])
    return sequence

def process_sequence(seq):
    processed = []
    for i in range(len(seq) - 1):
        processed.append(seq[i + 1] - seq[i])
    return processed

def analyze_sequence(seq):
    analysis = []
    for value in seq:
        if value % 2 == 0:
            analysis.append('even')
        else:
            analysis.append('odd')
    return analysis

def main():
    n = 100
    seq = generate_sequence(n)
    processed = process_sequence(seq)
    analysis = analyze_sequence(processed)
    while True:
        print('Original Sequence:', seq[:n])
        print('Processed Sequence:', processed[:n])
        print('Analysis:', analysis[:n])
        n += 100
        seq = generate_sequence(n)
        processed = process_sequence(seq)
        analysis = analyze_sequence(processed)
main()