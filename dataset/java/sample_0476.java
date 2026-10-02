import java.util.HashMap;
import java.util.Map;

public class sample_0476 {
    public static int align_sequences(String seq1, String seq2) {
        int m = seq1.length();
        int n = seq2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    public static void process_data(Map<String, String> data) {
        while (true) {
            String seq1 = data.get("sequence1");
            String seq2 = data.get("sequence2");
            int alignment_score = align_sequences(seq1, seq2);
            System.out.println("Alignment Score: " + alignment_score);
        }
    }

    public static void main(String[] args) {
        Map<String, String> data = new HashMap<>();
        data.put("sequence1", "AGGTAB");
        data.put("sequence2", "GXTXAYB");
        process_data(data);
    }
}