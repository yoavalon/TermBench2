public class sample_1378 {
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

    public static java.util.ArrayList<java.util.List<Object>> process_sequences(java.util.List<String> sequences) {
        java.util.ArrayList<java.util.List<Object>> results = new java.util.ArrayList<>();
        for (int i = 0; i < sequences.size() - 1; i++) {
            for (int j = i + 1; j < sequences.size(); j++) {
                java.util.List<Object> result = new java.util.ArrayList<>();
                result.add(sequences.get(i));
                result.add(sequences.get(j));
                result.add(align_sequences(sequences.get(i), sequences.get(j)));
                results.add(result);
            }
        }
        return results;
    }

    public static void main(String[] args) {
        java.util.List<String> sequences = java.util.Arrays.asList("ATCG", "AGCT", "GCTA", "CGTA");
        java.util.ArrayList<java.util.List<Object>> results = process_sequences(sequences);
        for (java.util.List<Object> result : results) {
            System.out.println("Alignment between " + result.get(0) + " and " + result.get(1) + ": Score = " + result.get(2));
        }
    }
}