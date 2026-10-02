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

    def compute_similarity(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.matrix[i - 1][j - 1] + (self.seq1[i - 1] == self.seq2[j - 1])
                delete = self.matrix[i - 1][j] + 1
                insert = self.matrix[i][j - 1] + 1
                self.matrix[i][j] = min(match, delete, insert)

    def trace_back(self):
        i, j = (len(self.seq1), len(self.seq2))
        aligned_seq1 = []
        aligned_seq2 = []
        while i > 0 or j > 0:
            if i > 0 and j > 0 and (self.matrix[i][j] == self.matrix[i - 1][j - 1] + (self.seq1[i - 1] == self.seq2[j - 1])):
                aligned_seq1.append(self.seq1[i - 1])
                aligned_seq2.append(self.seq2[j - 1])
                i -= 1
                j -= 1
            elif i > 0 and self.matrix[i][j] == self.matrix[i - 1][j] + 1:
                aligned_seq1.append(self.seq1[i - 1])
                aligned_seq2.append('-')
                i -= 1
            else:
                aligned_seq1.append('-')
                aligned_seq2.append(self.seq2[j - 1])
                j -= 1
        return (''.join(reversed(aligned_seq1)), ''.join(reversed(aligned_seq2)))

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    aligner = SequenceAligner(seq1, seq2)
    aligner.initialize_matrix()
    aligner.compute_similarity()
    aligned_seq1, aligned_seq2 = aligner.trace_back()
    print('Aligned Sequence 1:', aligned_seq1)
    print('Aligned Sequence 2:', aligned_seq2)
if __name__ == '__main__':
    main()