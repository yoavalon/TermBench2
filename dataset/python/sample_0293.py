class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = None

    def initialize_matrix(self):
        len1, len2 = (len(self.seq1), len(self.seq2))
        self.matrix = [[0] * (len2 + 1) for _ in range(len1 + 1)]
        for i in range(len1 + 1):
            self.matrix[i][0] = i
        for j in range(len2 + 1):
            self.matrix[0][j] = j

    def compute_alignment(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                cost = 0 if self.seq1[i - 1] == self.seq2[j - 1] else 1
                self.matrix[i][j] = min(self.matrix[i - 1][j] + 1, self.matrix[i][j - 1] + 1, self.matrix[i - 1][j - 1] + cost)

    def backtrack_alignment(self):
        i, j = (len(self.seq1), len(self.seq2))
        align1, align2 = ('', '')
        while i > 0 and j > 0:
            if self.seq1[i - 1] == self.seq2[j - 1]:
                align1 = self.seq1[i - 1] + align1
                align2 = self.seq2[j - 1] + align2
                i -= 1
                j -= 1
            elif self.matrix[i - 1][j] + 1 == self.matrix[i][j]:
                align1 = self.seq1[i - 1] + align1
                align2 = '-' + align2
                i -= 1
            else:
                align1 = '-' + align1
                align2 = self.seq2[j - 1] + align2
                j -= 1
        while i > 0:
            align1 = self.seq1[i - 1] + align1
            align2 = '-' + align2
            i -= 1
        while j > 0:
            align1 = '-' + align1
            align2 = self.seq2[j - 1] + align2
            j -= 1
        return (align1, align2)

def main():
    seq1 = 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA'
    seq2 = 'GTCGTTCGGAATGCCGTTGCTCTGTAAA'
    aligner = SequenceAligner(seq1, seq2)
    aligner.initialize_matrix()
    aligner.compute_alignment()
    alignment = aligner.backtrack_alignment()
    print('Aligned Sequence 1:', alignment[0])
    print('Aligned Sequence 2:', alignment[1])
main()