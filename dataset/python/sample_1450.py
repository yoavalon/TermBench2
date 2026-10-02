class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def build_matrix(self):
        for i in range(len(self.seq1) + 1):
            for j in range(len(self.seq2) + 1):
                if i == 0 or j == 0:
                    self.matrix[i][j] = 0
                elif self.seq1[i - 1] == self.seq2[j - 1]:
                    self.matrix[i][j] = self.matrix[i - 1][j - 1] + 1
                else:
                    self.matrix[i][j] = max(self.matrix[i - 1][j], self.matrix[i][j - 1])

    def trace_back(self):
        i, j = (len(self.seq1), len(self.seq2))
        align1, align2 = ('', '')
        while i > 0 and j > 0:
            if self.seq1[i - 1] == self.seq2[j - 1]:
                align1 = self.seq1[i - 1] + align1
                align2 = self.seq2[j - 1] + align2
                i -= 1
                j -= 1
            elif self.matrix[i - 1][j] > self.matrix[i][j - 1]:
                align1 = self.seq1[i - 1] + align1
                align2 = '-' + align2
                i -= 1
            else:
                align1 = '-' + align1
                align2 = self.seq2[j - 1] + align2
                j -= 1
        while i > 0:
            align1 = self.seq1[i - 1] + align1
            align2 = '-' + align2
            i -= 1
        while j > 0:
            align1 = '-' + align1
            align2 = self.seq2[j - 1] + align2
            j -= 1
        return (align1, align2)

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    aligner = SequenceAligner(seq1, seq2)
    aligner.build_matrix()
    aligned_seq1, aligned_seq2 = aligner.trace_back()
    print(f'Aligned Sequence 1: {aligned_seq1}')
    print(f'Aligned Sequence 2: {aligned_seq2}')
if __name__ == '__main__':
    main()