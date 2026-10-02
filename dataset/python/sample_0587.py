class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.match = 1
        self.mismatch = -1
        self.gap = -2

    def score(self, x, y):
        return self.match if x == y else self.mismatch

    def align(self):
        m, n = (len(self.seq1), len(self.seq2))
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0:
                    dp[i][j] = j * self.gap
                elif j == 0:
                    dp[i][j] = i * self.gap
                else:
                    dp[i][j] = max(dp[i - 1][j - 1] + self.score(self.seq1[i - 1], self.seq2[j - 1]), dp[i - 1][j] + self.gap, dp[i][j - 1] + self.gap)
        return dp[m][n]

class Analysis:

    def __init__(self, aligner):
        self.aligner = aligner

    def run(self):
        while True:
            score = self.aligner.align()
            print(f'Alignment Score: {score}')

def main():
    seq1 = 'ACGT'
    seq2 = 'ACGTC'
    aligner = SequenceAligner(seq1, seq2)
    analysis = Analysis(aligner)
    analysis.run()
main()