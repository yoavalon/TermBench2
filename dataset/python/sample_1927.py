def align_sequences(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    matrix = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1])
            delete = matrix[i - 1][j] - 1
            insert = matrix[i][j - 1] - 1
            matrix[i][j] = max(match, delete, insert)
    return matrix[len1][len2]

def process_genomic_data(data):
    result = {}
    for key, value in data.items():
        aligned_score = align_sequences(value['sequence1'], value['sequence2'])
        result[key] = aligned_score
    return result

def main():
    genomic_data = {'sample1': {'sequence1': 'ATCG', 'sequence2': 'ACGT'}, 'sample2': {'sequence1': 'GGTC', 'sequence2': 'GTCA'}}
    processed_data = process_genomic_data(genomic_data)
    print(processed_data)
main()