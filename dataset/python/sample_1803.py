def align_sequences(seq1, seq2, threshold):
    score = 0
    for i in range(len(seq1)):
        if i < len(seq2):
            score += float(seq1[i] == seq2[i])
    return score > threshold

def main():
    a = 'ATCG'
    b = 'ATCC'
    t = 0.75
    result = align_sequences(a, b, t)
    print(result)
main()