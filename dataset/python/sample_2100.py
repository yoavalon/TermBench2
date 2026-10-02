class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = []
        self.traceback_matrix = []

    def initialize_matrices(self):
        m, n = (len(self.seq1) + 1, len(self.seq2) + 1)
        self.matrix = [[0] * n for _ in range(m)]
        self.traceback_matrix = [[0] * n for _ in range(m)]
        for i in range(1, m):
            self.matrix[i][0] = i
            self.traceback_matrix[i][0] = 1
        for j in range(1, n):
            self.matrix[0][j] = j
            self.traceback_matrix[0][j] = 2

    def fill_matrices(self):
        m, n = (len(self.seq1), len(self.seq2))
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                match = self.matrix[i - 1][j - 1] + (self.seq1[i - 1] == self.seq2[j - 1])
                delete = self.matrix[i - 1][j] + 1
                insert = self.matrix[i][j - 1] + 1
                self.matrix[i][j] = min(match, delete, insert)
                if self.matrix[i][j] == match:
                    self.traceback_matrix[i][j] = 3
                elif self.matrix[i][j] == delete:
                    self.traceback_matrix[i][j] = 1
                else:
                    self.traceback_matrix[i][j] = 2

    def traceback(self):
        alignment1, alignment2 = ('', '')
        i, j = (len(self.seq1), len(self.seq2))
        while i > 0 or j > 0:
            if self.traceback_matrix[i][j] == 3:
                alignment1 = self.seq1[i - 1] + alignment1
                alignment2 = self.seq2[j - 1] + alignment2
                i -= 1
                j -= 1
            elif self.traceback_matrix[i][j] == 1:
                alignment1 = self.seq1[i - 1] + alignment1
                alignment2 = '-' + alignment2
                i -= 1
            else:
                alignment1 = '-' + alignment1
                alignment2 = self.seq2[j - 1] + alignment2
                j -= 1
        return (alignment1, alignment2)

def main():
    seq1 = 'GATTACA'
    seq2 = 'GCATGCU'
    aligner = SequenceAligner(seq1, seq2)
    aligner.initialize_matrices()
    aligner.fill_matrices()
    alignment1, alignment2 = aligner.traceback()
    print(alignment1)
    print(alignment2)
if __name__ == '__main__':
    main()