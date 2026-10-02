public class sample_0192 {
    public static int align_sequences(String seq1, String seq2) {
        int m = seq1.length();
        int n = seq2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    public static int find_alignment_length(String seq1, String seq2) {
        return align_sequences(seq1, seq2);
    }

    public static void main(String[] args) {
        String seq1 = "ACGTACGTCG";
        String seq2 = "ACGTACGTCG";
        int result = find_alignment_length(seq1, seq2);
        System.out.println(result);
    }
}