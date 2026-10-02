class GenomicAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def _score(self, a, b):
        return 1 if a == b else -1

    def _fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.matrix[i - 1][j - 1] + self._score(self.seq1[i - 1], self.seq2[j - 1])
                delete = self.matrix[i - 1][j] - 1
                insert = self.matrix[i][j - 1] - 1
                self.matrix[i][j] = max(match, delete, insert)

    def _traceback(self, i, j):
        if i == 0 or j == 0:
            return ('', '')
        if self.matrix[i][j] == self.matrix[i - 1][j - 1] + self._score(self.seq1[i - 1], self.seq2[j - 1]):
            s1, s2 = self._traceback(i - 1, j - 1)
            return (self.seq1[i - 1] + s1, self.seq2[j - 1] + s2)
        elif self.matrix[i][j] == self.matrix[i - 1][j] - 1:
            s1, s2 = self._traceback(i - 1, j)
            return (self.seq1[i - 1] + s1, '-' + s2)
        else:
            s1, s2 = self._traceback(i, j - 1)
            return ('-' + s1, self.seq2[j - 1] + s2)

    def align(self):
        self._fill_matrix()
        return self._traceback(len(self.seq1), len(self.seq2))

def main():
    seq1 = 'ACGTGACGTG'
    seq2 = 'GTCGTGTCG'
    aligner = GenomicAligner(seq1, seq2)
    aligned_seq1, aligned_seq2 = aligner.align()
    print('Aligned Sequence 1:', aligned_seq1)
    print('Aligned Sequence 2:', aligned_seq2)
if __name__ == '__main__':
    main()