class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                if self.seq1[i - 1] == self.seq2[j - 1]:
                    self.matrix[i][j] = self.matrix[i - 1][j - 1] + 1
                else:
                    self.matrix[i][j] = max(self.matrix[i - 1][j], self.matrix[i][j - 1])

    def trace_back(self):
        i, j = (len(self.seq1), len(self.seq2))
        alignment = []
        while i > 0 and j > 0:
            if self.seq1[i - 1] == self.seq2[j - 1]:
                alignment.append(self.seq1[i - 1])
                i -= 1
                j -= 1
            elif self.matrix[i - 1][j] > self.matrix[i][j - 1]:
                i -= 1
            else:
                j -= 1
        alignment.reverse()
        return ''.join(alignment)

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    aligner = SequenceAligner(seq1, seq2)
    aligner.fill_matrix()
    result = aligner.trace_back()
    print('Aligned sequence:', result)
if __name__ == '__main__':
    main()