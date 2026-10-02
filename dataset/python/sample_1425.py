class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.score_matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]
        self.trace_matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def fill_matrices(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.score_matrix[i - 1][j - 1] + (self.seq1[i - 1] == self.seq2[j - 1])
                delete = self.score_matrix[i - 1][j] - 1
                insert = self.score_matrix[i][j - 1] - 1
                self.score_matrix[i][j] = max(match, delete, insert)
                if self.score_matrix[i][j] == match:
                    self.trace_matrix[i][j] = 1
                elif self.score_matrix[i][j] == delete:
                    self.trace_matrix[i][j] = 2
                else:
                    self.trace_matrix[i][j] = 3

    def trace_back(self):
        i, j = (len(self.seq1), len(self.seq2))
        aligned_seq1 = []
        aligned_seq2 = []
        while i > 0 and j > 0:
            if self.trace_matrix[i][j] == 1:
                aligned_seq1.append(self.seq1[i - 1])
                aligned_seq2.append(self.seq2[j - 1])
                i -= 1
                j -= 1
            elif self.trace_matrix[i][j] == 2:
                aligned_seq1.append(self.seq1[i - 1])
                aligned_seq2.append('-')
                i -= 1
            else:
                aligned_seq1.append('-')
                aligned_seq2.append(self.seq2[j - 1])
                j -= 1
        aligned_seq1.reverse()
        aligned_seq2.reverse()
        return (''.join(aligned_seq1), ''.join(aligned_seq2))

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    aligner = SequenceAligner(seq1, seq2)
    aligner.fill_matrices()
    aligned_seq1, aligned_seq2 = aligner.trace_back()
    print('Aligned Sequence 1:', aligned_seq1)
    print('Aligned Sequence 2:', aligned_seq2)
main()