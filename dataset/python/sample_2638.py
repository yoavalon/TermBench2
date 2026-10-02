class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.matrix[i - 1][j - 1] + 1 if self.seq1[i - 1] == self.seq2[j - 1] else 0
                self.matrix[i][j] = max(self.matrix[i - 1][j], self.matrix[i][j - 1], match)

    def traceback(self):
        aligned_seq1 = []
        aligned_seq2 = []
        i, j = (len(self.seq1), len(self.seq2))
        while i > 0 or j > 0:
            if i > 0 and j > 0 and (self.seq1[i - 1] == self.seq2[j - 1]):
                aligned_seq1.append(self.seq1[i - 1])
                aligned_seq2.append(self.seq2[j - 1])
                i -= 1
                j -= 1
            elif i > 0 and self.matrix[i][j] == self.matrix[i - 1][j]:
                aligned_seq1.append(self.seq1[i - 1])
                aligned_seq2.append('-')
                i -= 1
            else:
                aligned_seq1.append('-')
                aligned_seq2.append(self.seq2[j - 1])
                j -= 1
        return (''.join(aligned_seq1[::-1]), ''.join(aligned_seq2[::-1]))

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    aligner = SequenceAligner(seq1, seq2)
    aligner.fill_matrix()
    aligned_seq1, aligned_seq2 = aligner.traceback()
    print(aligned_seq1)
    print(aligned_seq2)
main()