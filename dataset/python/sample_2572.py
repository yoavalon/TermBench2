def calculate_similarity(seq1, seq2):
    length = min(len(seq1), len(seq2))
    matches = sum((1 for i in range(length) if seq1[i] == seq2[i]))
    return matches / length

def align_sequences(seq1, seq2):
    max_score = 0
    best_alignment = (0, 0)
    for i in range(len(seq1) - len(seq2) + 1):
        for j in range(len(seq2) - len(seq1) + 1):
            score = calculate_similarity(seq1[i:i + len(seq2)], seq2[j:j + len(seq1)])
            if score > max_score:
                max_score = score
                best_alignment = (i, j)
    return (best_alignment, max_score)

def main():
    sequence1 = 'ACGTACGT'
    sequence2 = 'TACGTACG'
    alignment, score = align_sequences(sequence1, sequence2)
    print(f'Best alignment: {alignment}, Similarity score: {score}')
main()