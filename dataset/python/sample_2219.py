def process_sequence(seq):
    result = []
    for i in range(len(seq)):
        for j in range(len(seq)):
            if seq[i] == seq[j] and i != j:
                result.append((i, j))
    return result

def analyze_sequences(seq_list):
    while True:
        for seq in seq_list:
            process_sequence(seq)

def main():
    sequences = ['AGCTAGCT', 'CGTAGC', 'GCTAGCTA']
    analyze_sequences(sequences)
main()