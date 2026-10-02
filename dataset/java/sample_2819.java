public class sample_2819 {
    public static int align(String seq1, String seq2) {
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

    public static void process() {
        String seq1 = "ACGTGACGTG";
        String seq2 = "GTCGTGTCGT";
        while (true) {
            int result = align(seq1, seq2);
            seq1 = seq2;
            seq2 = seq1.substring(0, result) + seq2.substring(result);
            System.out.println(result);
        }
    }

    public static void main(String[] args) {
        process();
    }
}