public class sample_0123 {
    public static int align_sequences(String seq1, String seq2) {
        int len1 = seq1.length();
        int len2 = seq2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                dp[i][j] = Math.max(dp[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : 0), Math.max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[len1][len2];
    }

    public static int process_data(String[] data) {
        String seq1 = data[0];
        String seq2 = data[1];
        int result = align_sequences(seq1, seq2);
        return result;
    }

    public static void main(String[] args) {
        String[] data = {"AGGTAB", "GXTXAYB"};
        System.out.println(process_data(data));
    }
}