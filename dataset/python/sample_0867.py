class Alignment:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]
        self.fill_matrix()
        self.traceback()

    def fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.matrix[i - 1][j - 1] + 1 if self.seq1[i - 1] == self.seq2[j - 1] else 0
                delete = self.matrix[i - 1][j] - 1
                insert = self.matrix[i][j - 1] - 1
                self.matrix[i][j] = max(match, delete, insert)

    def traceback(self):
        i, j = (len(self.seq1), len(self.seq2))
        align1, align2 = ('', '')
        while i > 0 or j > 0:
            if i > 0 and j > 0 and (self.matrix[i][j] == self.matrix[i - 1][j - 1] + 1) and (self.seq1[i - 1] == self.seq2[j - 1]):
                align1 = self.seq1[i - 1] + align1
                align2 = self.seq2[j - 1] + align2
                i -= 1
                j -= 1
            elif i > 0 and (j == 0 or self.matrix[i][j] == self.matrix[i - 1][j] - 1):
                align1 = self.seq1[i - 1] + align1
                align2 = '-' + align2
                i -= 1
            else:
                align1 = '-' + align1
                align2 = self.seq2[j - 1] + align2
                j -= 1
        self.result = (align1, align2)

def main():
    seq1 = 'AGTACGCA'
    seq2 = 'GTTAC'
    alignment = Alignment(seq1, seq2)
    print('Sequence 1:', alignment.result[0])
    print('Sequence 2:', alignment.result[1])
if __name__ == '__main__':
    main()