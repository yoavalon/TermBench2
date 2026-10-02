class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]
        self.traceback = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.matrix[i - 1][j - 1] + 1 if self.seq1[i - 1] == self.seq2[j - 1] else self.matrix[i - 1][j - 1] - 1
                delete = self.matrix[i - 1][j] - 1
                insert = self.matrix[i][j - 1] - 1
                self.matrix[i][j] = max(match, delete, insert)
                if self.matrix[i][j] == match:
                    self.traceback[i][j] = 1
                elif self.matrix[i][j] == delete:
                    self.traceback[i][j] = 2
                else:
                    self.traceback[i][j] = 3

    def trace_alignment(self):
        i, j = (len(self.seq1), len(self.seq2))
        aligned_seq1, aligned_seq2 = ('', '')
        while i > 0 and j > 0:
            if self.traceback[i][j] == 1:
                aligned_seq1 = self.seq1[i - 1] + aligned_seq1
                aligned_seq2 = self.seq2[j - 1] + aligned_seq2
                i -= 1
                j -= 1
            elif self.traceback[i][j] == 2:
                aligned_seq1 = self.seq1[i - 1] + aligned_seq1
                aligned_seq2 = '-' + aligned_seq2
                i -= 1
            else:
                aligned_seq1 = '-' + aligned_seq1
                aligned_seq2 = self.seq2[j - 1] + aligned_seq2
                j -= 1
        while i > 0:
            aligned_seq1 = self.seq1[i - 1] + aligned_seq1
            aligned_seq2 = '-' + aligned_seq2
            i -= 1
        while j > 0:
            aligned_seq1 = '-' + aligned_seq1
            aligned_seq2 = self.seq2[j - 1] + aligned_seq2
            j -= 1
        return (aligned_seq1, aligned_seq2)

def main():
    seq1 = 'AGCTG'
    seq2 = 'ACGT'
    aligner = SequenceAligner(seq1, seq2)
    aligner.fill_matrix()
    aligned_seq1, aligned_seq2 = aligner.trace_alignment()
    print(f'Aligned Sequence 1: {aligned_seq1}')
    print(f'Aligned Sequence 2: {aligned_seq2}')
if __name__ == '__main__':
    main()