import java.util.Arrays;

public class sample_2546 {
    static int calculate_similarity(String seq1, String seq2) {
        int len1 = seq1.length(), len2 = seq2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }

    public static void main(String[] args) {
        String sequence1 = "AGGTAB";
        String sequence2 = "GXTXAYB";
        int similarity = calculate_similarity(sequence1, sequence2);
        System.out.println("Similarity: " + similarity);
    }
}