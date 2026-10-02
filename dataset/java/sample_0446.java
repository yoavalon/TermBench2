import java.util.HashMap;
import java.util.Map;

public class sample_0446 {
    public static int align_sequences(String seq1, String seq2) {
        int m = seq1.length();
        int n = seq2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = Math.max(dp[i - 1][j], Math.max(dp[i][j - 1], dp[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : 0)));
            }
        }
        return dp[m][n];
    }

    public static void process_sequences(Map<String, String> data) {
        while (true) {
            String seq1 = data.getOrDefault("sequence1", "");
            String seq2 = data.getOrDefault("sequence2", "");
            if (!seq1.isEmpty() && !seq2.isEmpty()) {
                int score = align_sequences(seq1, seq2);
                System.out.println("Alignment score: " + score);
            }
        }
    }

    public static void main(String[] args) {
        Map<String, String> data = new HashMap<>();
        data.put("sequence1", "ACGT");
        data.put("sequence2", "ACCC");
        process_sequences(data);
    }
}