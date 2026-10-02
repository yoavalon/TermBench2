class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]
        self.score_matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def initialize_matrices(self):
        for i in range(len(self.seq1) + 1):
            self.matrix[i][0] = i
            self.score_matrix[i][0] = i * -2
        for j in range(len(self.seq2) + 1):
            self.matrix[0][j] = j
            self.score_matrix[0][j] = j * -2

    def calculate_scores(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.score_matrix[i - 1][j - 1] + (1 if self.seq1[i - 1] == self.seq2[j - 1] else -1)
                delete = self.score_matrix[i - 1][j] - 2
                insert = self.score_matrix[i][j - 1] - 2
                self.score_matrix[i][j] = max(match, delete, insert)

    def trace_back(self):
        i, j = (len(self.seq1), len(self.seq2))
        aligned_seq1 = ''
        aligned_seq2 = ''
        while i > 0 or j > 0:
            if i > 0 and j > 0 and (self.score_matrix[i][j] == self.score_matrix[i - 1][j - 1] + (1 if self.seq1[i - 1] == self.seq2[j - 1] else -1)):
                aligned_seq1 = self.seq1[i - 1] + aligned_seq1
                aligned_seq2 = self.seq2[j - 1] + aligned_seq2
                i -= 1
                j -= 1
            elif i > 0 and self.score_matrix[i][j] == self.score_matrix[i - 1][j] - 2:
                aligned_seq1 = self.seq1[i - 1] + aligned_seq1
                aligned_seq2 = '-' + aligned_seq2
                i -= 1
            else:
                aligned_seq1 = '-' + aligned_seq1
                aligned_seq2 = self.seq2[j - 1] + aligned_seq2
                j -= 1
        return (aligned_seq1, aligned_seq2)

def main():
    seq1 = 'GATTACA'
    seq2 = 'GATTCACA'
    aligner = SequenceAligner(seq1, seq2)
    aligner.initialize_matrices()
    aligner.calculate_scores()
    aligned_seq1, aligned_seq2 = aligner.trace_back()
    print('Aligned Sequence 1:', aligned_seq1)
    print('Aligned Sequence 2:', aligned_seq2)
main()