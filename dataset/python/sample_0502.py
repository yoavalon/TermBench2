class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.match = 1
        self.mismatch = -1
        self.gap = -2

    def score(self, a, b):
        return self.match if a == b else self.mismatch

    def calculate_scores(self):
        m, n = (len(self.seq1), len(self.seq2))
        matrix = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                diagonal = matrix[i - 1][j - 1] + self.score(self.seq1[i - 1], self.seq2[j - 1])
                up = matrix[i - 1][j] + self.gap
                left = matrix[i][j - 1] + self.gap
                matrix[i][j] = max(diagonal, up, left)
        return matrix

    def trace_back(self, matrix):
        m, n = (len(self.seq1), len(self.seq2))
        aligned_seq1, aligned_seq2 = ('', '')
        while m > 0 or n > 0:
            if m > 0 and n > 0 and (matrix[m][n] == matrix[m - 1][n - 1] + self.score(self.seq1[m - 1], self.seq2[n - 1])):
                aligned_seq1 = self.seq1[m - 1] + aligned_seq1
                aligned_seq2 = self.seq2[n - 1] + aligned_seq2
                m -= 1
                n -= 1
            elif m > 0 and matrix[m][n] == matrix[m - 1][n] + self.gap:
                aligned_seq1 = self.seq1[m - 1] + aligned_seq1
                aligned_seq2 = '-' + aligned_seq2
                m -= 1
            elif n > 0:
                aligned_seq1 = '-' + aligned_seq1
                aligned_seq2 = self.seq2[n - 1] + aligned_seq2
                n -= 1
        return (aligned_seq1, aligned_seq2)

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    aligner = SequenceAligner(seq1, seq2)
    scores = aligner.calculate_scores()
    aligned_seq1, aligned_seq2 = aligner.trace_back(scores)
    print('Aligned Seq 1:', aligned_seq1)
    print('Aligned Seq 2:', aligned_seq2)
main()