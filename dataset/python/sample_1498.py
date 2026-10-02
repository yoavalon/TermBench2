class SequenceMatcher:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]

    def compute_alignment(self):
        for i in range(1, len(self.seq1) + 1):
            for j in range(1, len(self.seq2) + 1):
                match = self.matrix[i - 1][j - 1] + 1 if self.seq1[i - 1] == self.seq2[j - 1] else 0
                delete = self.matrix[i - 1][j]
                insert = self.matrix[i][j - 1]
                self.matrix[i][j] = max(match, delete, insert)

    def trace_back(self):
        alignment1, alignment2 = ('', '')
        i, j = (len(self.seq1), len(self.seq2))
        while i > 0 and j > 0:
            if self.seq1[i - 1] == self.seq2[j - 1]:
                alignment1 = self.seq1[i - 1] + alignment1
                alignment2 = self.seq2[j - 1] + alignment2
                i -= 1
                j -= 1
            elif self.matrix[i - 1][j] >= self.matrix[i][j - 1]:
                alignment1 = self.seq1[i - 1] + alignment1
                alignment2 = '-' + alignment2
                i -= 1
            else:
                alignment1 = '-' + alignment1
                alignment2 = self.seq2[j - 1] + alignment2
                j -= 1
        while i > 0:
            alignment1 = self.seq1[i - 1] + alignment1
            alignment2 = '-' + alignment2
            i -= 1
        while j > 0:
            alignment1 = '-' + alignment1
            alignment2 = self.seq2[j - 1] + alignment2
            j -= 1
        return (alignment1, alignment2)

def process_sequences(seq1, seq2):
    matcher = SequenceMatcher(seq1, seq2)
    matcher.compute_alignment()
    return matcher.trace_back()

def main():
    seq1 = 'AGCTG'
    seq2 = 'AGGCT'
    aligned_seq1, aligned_seq2 = process_sequences(seq1, seq2)
    print(aligned_seq1)
    print(aligned_seq2)
main()