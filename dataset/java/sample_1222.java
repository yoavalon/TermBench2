public class sample_1222 {
    public static int genomic_align(String seq1, String seq2) {
        int m = seq1.length();
        int n = seq2.length();
        int[][] score = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int match = score[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : 0);
                int delete = score[i - 1][j] - 1;
                int insert = score[i][j - 1] - 1;
                score[i][j] = Math.max(match, Math.max(delete, insert));
            }
        }
        return score[m][n];
    }

    public static void main(String[] args) {
        genomic_align("ATCG", "ACGT");
    }
}