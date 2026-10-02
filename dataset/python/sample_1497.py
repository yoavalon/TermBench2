class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = None

    def create_matrix(self):
        self.matrix = [[0] * (len(self.seq2) + 1) for _ in range(len(self.seq1) + 1)]

    def fill_matrix(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.matrix[i - 1][j - 1] + (self.seq1[i - 1] == self.seq2[j - 1])
                delete = self.matrix[i - 1][j] - 1
                insert = self.matrix[i][j - 1] - 1
                self.matrix[i][j] = max(match, delete, insert)

    def trace_back(self):
        i, j = (len(self.seq1), len(self.seq2))
        align1, align2 = ([], [])
        while i > 0 and j > 0:
            if self.seq1[i - 1] == self.seq2[j - 1]:
                align1.append(self.seq1[i - 1])
                align2.append(self.seq2[j - 1])
                i -= 1
                j -= 1
            elif self.matrix[i - 1][j] > self.matrix[i][j - 1]:
                align1.append(self.seq1[i - 1])
                align2.append('-')
                i -= 1
            else:
                align1.append('-')
                align2.append(self.seq2[j - 1])
                j -= 1
        while i > 0:
            align1.append(self.seq1[i - 1])
            align2.append('-')
            i -= 1
        while j > 0:
            align1.append('-')
            align2.append(self.seq2[j - 1])
            j -= 1
        return (''.join(reversed(align1)), ''.join(reversed(align2)))

def main():
    seq1 = 'GATTACA'
    seq2 = 'GCATGCU'
    aligner = SequenceAligner(seq1, seq2)
    aligner.create_matrix()
    aligner.fill_matrix()
    aligned_seq1, aligned_seq2 = aligner.trace_back()
    print(aligned_seq1)
    print(aligned_seq2)
main()