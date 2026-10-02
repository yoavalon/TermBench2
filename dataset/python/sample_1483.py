class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.score_matrix = []
        self.traceback_matrix = []
        self.max_score = 0
        self.max_position = (0, 0)

    def initialize_matrices(self):
        len1, len2 = (len(self.seq1), len(self.seq2))
        for i in range(len1 + 1):
            self.score_matrix.append([0] * (len2 + 1))
            self.traceback_matrix.append([0] * (len2 + 1))

    def fill_matrices(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.score_matrix[i - 1][j - 1] + (1 if self.seq1[i - 1] == self.seq2[j - 1] else -1)
                delete = self.score_matrix[i - 1][j] - 1
                insert = self.score_matrix[i][j - 1] - 1
                self.score_matrix[i][j] = max(match, delete, insert)
                if self.score_matrix[i][j] == match:
                    self.traceback_matrix[i][j] = 1
                elif self.score_matrix[i][j] == delete:
                    self.traceback_matrix[i][j] = 2
                else:
                    self.traceback_matrix[i][j] = 3
                if self.score_matrix[i][j] > self.max_score:
                    self.max_score = self.score_matrix[i][j]
                    self.max_position = (i, j)

    def backtrack(self):
        aligned_seq1 = []
        aligned_seq2 = []
        i, j = self.max_position
        while i > 0 and j > 0:
            if self.traceback_matrix[i][j] == 1:
                aligned_seq1.append(self.seq1[i - 1])
                aligned_seq2.append(self.seq2[j - 1])
                i -= 1
                j -= 1
            elif self.traceback_matrix[i][j] == 2:
                aligned_seq1.append(self.seq1[i - 1])
                aligned_seq2.append('-')
                i -= 1
            else:
                aligned_seq1.append('-')
                aligned_seq2.append(self.seq2[j - 1])
                j -= 1
        return (''.join(reversed(aligned_seq1)), ''.join(reversed(aligned_seq2)))

def main():
    seq1 = 'AGCTG'
    seq2 = 'CGTAT'
    aligner = SequenceAligner(seq1, seq2)
    aligner.initialize_matrices()
    aligner.fill_matrices()
    aligned_seq1, aligned_seq2 = aligner.backtrack()
    print(aligned_seq1)
    print(aligned_seq2)
if __name__ == '__main__':
    main()