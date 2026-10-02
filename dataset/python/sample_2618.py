class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.m = len(seq1)
        self.n = len(seq2)
        self.dp = [[0] * (self.n + 1) for _ in range(self.m + 1)]

    def compute_alignment(self):
        for i in range(self.m + 1):
            for j in range(self.n + 1):
                if i == 0:
                    self.dp[i][j] = j
                elif j == 0:
                    self.dp[i][j] = i
                elif self.seq1[i - 1] == self.seq2[j - 1]:
                    self.dp[i][j] = self.dp[i - 1][j - 1]
                else:
                    self.dp[i][j] = 1 + min(self.dp[i][j - 1], self.dp[i - 1][j], self.dp[i - 1][j - 1])

    def get_alignment(self):
        alignment1 = ''
        alignment2 = ''
        i = self.m
        j = self.n
        while i > 0 and j > 0:
            if self.seq1[i - 1] == self.seq2[j - 1]:
                alignment1 = self.seq1[i - 1] + alignment1
                alignment2 = self.seq2[j - 1] + alignment2
                i -= 1
                j -= 1
            elif self.dp[i - 1][j] < self.dp[i][j - 1] and self.dp[i - 1][j] < self.dp[i - 1][j - 1]:
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

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    aligner = SequenceAligner(seq1, seq2)
    aligner.compute_alignment()
    alignment1, alignment2 = aligner.get_alignment()
    print('Alignment 1:', alignment1)
    print('Alignment 2:', alignment2)
main()