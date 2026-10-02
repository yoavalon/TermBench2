class GenomicAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def _fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                if self.seq1[i - 1] == self.seq2[j - 1]:
                    self.matrix[i][j] = self.matrix[i - 1][j - 1] + 1
                else:
                    self.matrix[i][j] = max(self.matrix[i - 1][j], self.matrix[i][j - 1])

    def _traceback(self):
        alignment1 = []
        alignment2 = []
        i, j = (len(self.seq1), len(self.seq2))
        while i > 0 and j > 0:
            if self.seq1[i - 1] == self.seq2[j - 1]:
                alignment1.append(self.seq1[i - 1])
                alignment2.append(self.seq2[j - 1])
                i -= 1
                j -= 1
            elif self.matrix[i - 1][j] > self.matrix[i][j - 1]:
                alignment1.append(self.seq1[i - 1])
                alignment2.append('-')
                i -= 1
            else:
                alignment1.append('-')
                alignment2.append(self.seq2[j - 1])
                j -= 1
        alignment1.reverse()
        alignment2.reverse()
        return (alignment1, alignment2)

    def align(self):
        self._fill_matrix()
        return self._traceback()

def main():
    seq1 = 'AGTACGCA'
    seq2 = 'TGACGTCA'
    aligner = GenomicAligner(seq1, seq2)
    result = aligner.align()
    print('Alignment 1:', ''.join(result[0]))
    print('Alignment 2:', ''.join(result[1]))
if __name__ == '__main__':
    main()