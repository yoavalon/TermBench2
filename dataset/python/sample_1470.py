class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.matrix[i - 1][j - 1] + (1 if self.seq1[i - 1] == self.seq2[j - 1] else -1)
                delete = self.matrix[i - 1][j] - 1
                insert = self.matrix[i][j - 1] - 1
                self.matrix[i][j] = max(match, delete, insert)

    def backtrack(self):
        i, j = (len(self.seq1), len(self.seq2))
        aligned_seq1 = ''
        aligned_seq2 = ''
        while i > 0 or j > 0:
            if i > 0 and j > 0 and (self.matrix[i][j] == self.matrix[i - 1][j - 1] + (1 if self.seq1[i - 1] == self.seq2[j - 1] else -1)):
                aligned_seq1 = self.seq1[i - 1] + aligned_seq1
                aligned_seq2 = self.seq2[j - 1] + aligned_seq2
                i -= 1
                j -= 1
            elif i > 0 and self.matrix[i][j] == self.matrix[i - 1][j] - 1:
                aligned_seq1 = self.seq1[i - 1] + aligned_seq1
                aligned_seq2 = '-' + aligned_seq2
                i -= 1
            else:
                aligned_seq1 = '-' + aligned_seq1
                aligned_seq2 = self.seq2[j - 1] + aligned_seq2
                j -= 1
        return (aligned_seq1, aligned_seq2)

def main():
    seq1 = 'ACGTGACGTG'
    seq2 = 'ACGTTACGTG'
    aligner = SequenceAligner(seq1, seq2)
    aligner.fill_matrix()
    aligned_seq1, aligned_seq2 = aligner.backtrack()
    print('Aligned Sequence 1:', aligned_seq1)
    print('Aligned Sequence 2:', aligned_seq2)
if __name__ == '__main__':
    main()