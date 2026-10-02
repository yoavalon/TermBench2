public class sample_2618 {

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

        void compute_alignment() {
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0) {
                        dp[i][j] = j;
                    } else if (j == 0) {
                        dp[i][j] = i;
                    } else if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = 1 + Math.min(dp[i][j - 1], Math.min(dp[i - 1][j], dp[i - 1][j - 1]));
                    }
                }
            }
        }

        String[] get_alignment() {
            StringBuilder alignment1 = new StringBuilder();
            StringBuilder alignment2 = new StringBuilder();
            int i = m;
            int j = n;
            while (i > 0 && j > 0) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    alignment1.insert(0, seq1.charAt(i - 1));
                    alignment2.insert(0, seq2.charAt(j - 1));
                    i--;
                    j--;
                } else if (dp[i - 1][j] < dp[i][j - 1] && dp[i - 1][j] < dp[i - 1][j - 1]) {
                    alignment1.insert(0, seq1.charAt(i - 1));
                    alignment2.insert(0, '-');
                    i--;
                } else {
                    alignment1.insert(0, '-');
                    alignment2.insert(0, seq2.charAt(j - 1));
                    j--;
                }
            }
            while (i > 0) {
                alignment1.insert(0, seq1.charAt(i - 1));
                alignment2.insert(0, '-');
                i--;
            }
            while (j > 0) {
                alignment1.insert(0, '-');
                alignment2.insert(0, seq2.charAt(j - 1));
                j--;
            }
            return new String[]{alignment1.toString(), alignment2.toString()};
        }
    }

    public static void main(String[] args) {
        sample_2618 sample = new sample_2618();
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        sample.SequenceAligner aligner = sample.new SequenceAligner(seq1, seq2);
        aligner.compute_alignment();
        String[] alignment = aligner.get_alignment();
        System.out.println("Alignment 1: " + alignment[0]);
        System.out.println("Alignment 2: " + alignment[1]);
    }
}