public class sample_1398 {
    public static int align_sequences(String seq1, String seq2) {
        int m = seq1.length();
        int n = seq2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int cost = (seq1.charAt(i - 1) == seq2.charAt(j - 1)) ? 0 : 1;
                dp[i][j] = Math.min(dp[i - 1][j] + 1, Math.min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost));
            }
        }
        return dp[m][n];
    }

    public static int process_sequences(String[][] sequences) {
        int total_cost = 0;
        for (String[] pair : sequences) {
            total_cost += align_sequences(pair[0], pair[1]);
        }
        return total_cost;
    }

    public static void main(String[] args) {
        String[][] sequences = {{"AGCT", "ACGT"}, {"GATTACA", "GCTACGA"}};
        int result = process_sequences(sequences);
        System.out.println(result);
    }
}