def calculate_alignment_score(seq1, seq2):
    score = 0
    for i in range(min(len(seq1), len(seq2))):
        if seq1[i] == seq2[i]:
            score += 1
    return score

def find_best_alignment(seq1, seq2):
    best_score = 0
    best_offset = 0
    for offset in range(-len(seq2), len(seq1)):
        shifted_seq2 = seq2[max(0, -offset):len(seq2) - max(0, offset)]
        score = calculate_alignment_score(seq1, shifted_seq2)
        if score > best_score:
            best_score = score
            best_offset = offset
    return (best_score, best_offset)

def main():
    sequence1 = 'ACGTACGTACG'
    sequence2 = 'GTACGTACGTA'
    score, offset = find_best_alignment(sequence1, sequence2)
    print(f'Best alignment score: {score}, Offset: {offset}')
main()