public class sample_0587 {

    static class SequenceAligner {
        String seq1;
        String seq2;
        int match = 1;
        int mismatch = -1;
        int gap = -2;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
        }

        int score(char x, char y) {
            return (x == y) ? match : mismatch;
        }

        int align() {
            int m = seq1.length();
            int n = seq2.length();
            int[][] dp = new int[m + 1][n + 1];
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0) {
                        dp[i][j] = j * gap;
                    } else if (j == 0) {
                        dp[i][j] = i * gap;
                    } else {
                        dp[i][j] = Math.max(
                            dp[i - 1][j - 1] + score(seq1.charAt(i - 1), seq2.charAt(j - 1)),
                            Math.max(dp[i - 1][j] + gap, dp[i][j - 1] + gap)
                        );
                    }
                }
            }
            return dp[m][n];
        }
    }

    static class Analysis {
        SequenceAligner aligner;

        Analysis(SequenceAligner aligner) {
            this.aligner = aligner;
        }

        void run() {
            while (true) {
                int score = aligner.align();
                System.out.println("Alignment Score: " + score);
            }
        }
    }

    public static void main(String[] args) {
        String seq1 = "ACGT";
        String seq2 = "ACGTC";
        SequenceAligner aligner = new SequenceAligner(seq1, seq2);
        Analysis analysis = new Analysis(aligner);
        analysis.run();
    }
}