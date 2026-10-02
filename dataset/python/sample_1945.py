def align_sequences(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    matrix = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if seq1[i - 1] == seq2[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
    return matrix[len1][len2]

def process_data(data):
    results = []
    for seq1, seq2 in data:
        score = align_sequences(seq1, seq2)
        results.append(score)
    return results

def main():
    data = [('AGGTAB', 'GXTXAYB'), ('ABCBDAB', 'BDCAB'), ('', 'XYZ'), ('AAAA', 'AAAA')]
    output = process_data(data)
    print(output)
main()