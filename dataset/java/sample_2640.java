public class sample_2640 {
    class SequenceAligner {
        String seq1;
        String seq2;
        int m;
        int n;
        int[][] dp;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.m = seq1.length();
            this.n = seq2.length();
            this.dp = new int[m + 1][n + 1];
        }

        void calculate_score() {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }

        String[] traceback() {
            int i = m;
            int j = n;
            String align1 = "";
            String align2 = "";
            while (i > 0 || j > 0) {
                if (i > 0 && j > 0 && (seq1.charAt(i - 1) == seq2.charAt(j - 1))) {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    i -= 1;
                    j -= 1;
                } else if (i > 0 && dp[i][j] == dp[i - 1][j]) {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = '-' + align2;
                    i -= 1;
                } else {
                    align1 = '-' + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    j -= 1;
                }
            }
            return new String[]{align1, align2};
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        sample_2640 sample = new sample_2640();
        SequenceAligner aligner = sample.new SequenceAligner(seq1, seq2);
        aligner.calculate_score();
        String[] result = aligner.traceback();
        System.out.println("Aligned Sequence 1: " + result[0]);
        System.out.println("Aligned Sequence 2: " + result[1]);
    }
}