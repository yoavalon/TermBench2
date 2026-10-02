class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.m = len(seq1)
        self.n = len(seq2)
        self.dp = [[0] * (self.n + 1) for _ in range(self.m + 1)]

    def calculate_score(self):
        for i in range(1, self.m + 1):
            for j in range(1, self.n + 1):
                if self.seq1[i - 1] == self.seq2[j - 1]:
                    self.dp[i][j] = self.dp[i - 1][j - 1] + 1
                else:
                    self.dp[i][j] = max(self.dp[i - 1][j], self.dp[i][j - 1])

    def traceback(self):
        i, j = (self.m, self.n)
        align1, align2 = ('', '')
        while i > 0 or j > 0:
            if i > 0 and j > 0 and (self.seq1[i - 1] == self.seq2[j - 1]):
                align1 = self.seq1[i - 1] + align1
                align2 = self.seq2[j - 1] + align2
                i -= 1
                j -= 1
            elif i > 0 and self.dp[i][j] == self.dp[i - 1][j]:
                align1 = self.seq1[i - 1] + align1
                align2 = '-' + align2
                i -= 1
            else:
                align1 = '-' + align1
                align2 = self.seq2[j - 1] + align2
                j -= 1
        return (align1, align2)

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    aligner = SequenceAligner(seq1, seq2)
    aligner.calculate_score()
    result = aligner.traceback()
    print('Aligned Sequence 1:', result[0])
    print('Aligned Sequence 2:', result[1])
if __name__ == '__main__':
    main()