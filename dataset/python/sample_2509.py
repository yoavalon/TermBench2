def compute_similarity(seq1, seq2):
    length = min(len(seq1), len(seq2))
    score = 0
    for i in range(length):
        if seq1[i] == seq2[i]:
            score += 1
    return score / length

def align_sequences(seq1, seq2):
    max_score = 0
    best_alignment = (seq1, seq2)
    for i in range(len(seq2)):
        shifted_seq = seq2[i:] + seq2[:i]
        score = compute_similarity(seq1, shifted_seq)
        if score > max_score:
            max_score = score
            best_alignment = (seq1, shifted_seq)
    return best_alignment

def main():
    sequence1 = 'ACGTACGTAC'
    sequence2 = 'TACGTACGTA'
    aligned_sequences = align_sequences(sequence1, sequence2)
    print('Aligned Sequences:', aligned_sequences)
main()