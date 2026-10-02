class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.matrix[i - 1][j - 1] + 1 if self.seq1[i - 1] == self.seq2[j - 1] else 0
                delete = self.matrix[i - 1][j] - 1
                insert = self.matrix[i][j - 1] - 1
                self.matrix[i][j] = max(match, delete, insert)

    def trace_back(self):
        i, j = (len(self.seq1), len(self.seq2))
        aligned_seq1 = []
        aligned_seq2 = []
        while i > 0 and j > 0:
            if self.seq1[i - 1] == self.seq2[j - 1]:
                aligned_seq1.append(self.seq1[i - 1])
                aligned_seq2.append(self.seq2[j - 1])
                i -= 1
                j -= 1
            elif self.matrix[i - 1][j] > self.matrix[i][j - 1]:
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
    seq1 = 'GATTACA'
    seq2 = 'CGATACG'
    aligner = SequenceAligner(seq1, seq2)
    aligner.fill_matrix()
    result1, result2 = aligner.trace_back()
    print(result1)
    print(result2)
main()