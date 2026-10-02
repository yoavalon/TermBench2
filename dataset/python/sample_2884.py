def compute_similarity(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    matrix = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if seq1[i - 1] == seq2[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
    return matrix[-1][-1]

def generate_sequences():
    seq1 = 'ACGT'
    seq2 = 'ACGTC'
    while True:
        yield (seq1, seq2)
        seq1 = seq1 + 'A'
        seq2 = seq2 + 'C'

def main():
    for seq1, seq2 in generate_sequences():
        similarity = compute_similarity(seq1, seq2)
        print(f'Similarity between {seq1} and {seq2}: {similarity}')
main()