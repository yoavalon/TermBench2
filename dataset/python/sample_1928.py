import numpy as np

def align_sequences(seq1, seq2, precision):

    def calculate_score(a, b):
        return np.where(a == b, 1, -1).sum()
    max_score = -np.inf
    best_alignment = None
    for i in range(len(seq1) - len(seq2) + 1):
        for j in range(len(seq2) - len(seq1) + 1):
            subseq1 = seq1[i:i + len(seq2)]
            subseq2 = seq2[j:j + len(seq1)]
            score = calculate_score(subseq1, subseq2)
            if score > max_score:
                max_score = score
                best_alignment = (subseq1, subseq2)
    return (best_alignment, max_score)

def main():
    seq1 = np.array([0.1, 0.2, 0.3, 0.4, 0.5])
    seq2 = np.array([0.1, 0.2, 0.3, 0.4, 0.5])
    precision = 1e-09
    alignment, score = align_sequences(seq1, seq2, precision)
    print('Alignment:', alignment, 'Score:', score)
main()