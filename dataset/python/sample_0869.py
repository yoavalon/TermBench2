class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2

    def score(self, a, b):
        return 1 if a == b else -1

    def align(self):
        m, n = (len(self.seq1), len(self.seq2))
        matrix = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            matrix[i][0] = i
        for j in range(1, n + 1):
            matrix[0][j] = j
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                match = matrix[i - 1][j - 1] + self.score(self.seq1[i - 1], self.seq2[j - 1])
                delete = matrix[i - 1][j] + 1
                insert = matrix[i][j - 1] + 1
                matrix[i][j] = min(match, delete, insert)
        return self.traceback(matrix, m, n)

    def traceback(self, matrix, i, j):
        align1, align2 = ('', '')
        while i > 0 or j > 0:
            if i > 0 and j > 0 and (matrix[i][j] == matrix[i - 1][j - 1] + self.score(self.seq1[i - 1], self.seq2[j - 1])):
                align1 = self.seq1[i - 1] + align1
                align2 = self.seq2[j - 1] + align2
                i -= 1
                j -= 1
            elif i > 0 and matrix[i][j] == matrix[i - 1][j] + 1:
                align1 = self.seq1[i - 1] + align1
                align2 = '-' + align2
                i -= 1
            else:
                align1 = '-' + align1
                align2 = self.seq2[j - 1] + align2
                j -= 1
        return (align1, align2)

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    aligner = SequenceAligner(seq1, seq2)
    result = aligner.align()
    print('Alignment 1:', result[0])
    print('Alignment 2:', result[1])
if __name__ == '__main__':
    main()