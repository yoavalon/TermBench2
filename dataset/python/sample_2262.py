def calculate_similarity(seq1, seq2, threshold):
    length = min(len(seq1), len(seq2))
    matches = 0
    for i in range(length):
        if seq1[i] == seq2[i]:
            matches += 1
    similarity = matches / length
    return similarity > threshold

def align_sequences(seq1, seq2, threshold):
    while True:
        if calculate_similarity(seq1, seq2, threshold):
            return True
        seq1 = seq1[1:] + seq1[:1]
        seq2 = seq2[1:] + seq2[:1]

def main():
    seq1 = 'ACGTACGTACGT'
    seq2 = 'GTACGTACGTAC'
    threshold = 0.8
    result = align_sequences(seq1, seq2, threshold)
    print(result)
main()