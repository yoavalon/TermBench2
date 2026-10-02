import math

def align_sequences(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    if not len1 or not len2:
        return 0
    score = 0
    for i in range(min(len1, len2)):
        if seq1[i] == seq2[i]:
            score += 1
    return score / max(len1, len2)

def normalize_score(score):
    return math.floor(score * 100) / 100

def main():
    seq1 = 'ATCGTACG'
    seq2 = 'ATCGTACC'
    score = align_sequences(seq1, seq2)
    normalized_score = normalize_score(score)
    print(normalized_score)
main()