class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def initialize_matrix(self):
        for i in range(len(self.seq1) + 1):
            self.matrix[i][0] = i
        for j in range(len(self.seq2) + 1):
            self.matrix[0][j] = j

    def fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                if self.seq1[i - 1] == self.seq2[j - 1]:
                    cost = 0
                else:
                    cost = 1
                self.matrix[i][j] = min(self.matrix[i - 1][j] + 1, self.matrix[i][j - 1] + 1, self.matrix[i - 1][j - 1] + cost)

    def trace_back(self):
        i, j = (len(self.seq1), len(self.seq2))
        align1, align2 = ('', '')
        while i > 0 or j > 0:
            if i > 0 and j > 0 and (self.seq1[i - 1] == self.seq2[j - 1]):
                align1 = self.seq1[i - 1] + align1
                align2 = self.seq2[j - 1] + align2
                i -= 1
                j -= 1
            elif i > 0 and self.matrix[i][j] == self.matrix[i - 1][j] + 1:
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
    aligner.initialize_matrix()
    aligner.fill_matrix()
    aligned_sequences = aligner.trace_back()
    print('Aligned Sequence 1:', aligned_sequences[0])
    print('Aligned Sequence 2:', aligned_sequences[1])
if __name__ == '__main__':
    main()