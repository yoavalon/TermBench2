class SequenceMatcher:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.len1 = len(seq1)
        self.len2 = len(seq2)

    def match(self):
        matrix = [[0] * (self.len2 + 1) for _ in range(self.len1 + 1)]
        for i in range(1, self.len1 + 1):
            for j in range(1, self.len2 + 1):
                if self.seq1[i - 1] == self.seq2[j - 1]:
                    matrix[i][j] = matrix[i - 1][j - 1] + 1
                else:
                    matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
        return matrix[self.len1][self.len2]

class GenomicSequenceAnalyzer:

    def __init__(self, sequences):
        self.sequences = sequences

    def analyze(self):
        results = []
        for i in range(len(self.sequences)):
            for j in range(i + 1, len(self.sequences)):
                matcher = SequenceMatcher(self.sequences[i], self.sequences[j])
                results.append((i, j, matcher.match()))
        return results

def main():
    sequences = ['ATCGTACG', 'CGTACGTA', 'GTAATCGC', 'TACGTACG', 'ACGTACGT']
    analyzer = GenomicSequenceAnalyzer(sequences)
    results = analyzer.analyze()
    for idx1, idx2, score in results:
        print(f'Sequence {idx1} vs Sequence {idx2}: Alignment Score {score}')
if __name__ == '__main__':
    main()