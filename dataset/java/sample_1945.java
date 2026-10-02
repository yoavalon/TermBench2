public class sample_1945 {
    public static int align_sequences(String seq1, String seq2) {
        int len1 = seq1.length();
        int len2 = seq2.length();
        int[][] matrix = new int[len1 + 1][len2 + 1];
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
        return matrix[len1][len2];
    }

    public static int[] process_data(String[][] data) {
        int[] results = new int[data.length];
        for (int i = 0; i < data.length; i++) {
            int score = align_sequences(data[i][0], data[i][1]);
            results[i] = score;
        }
        return results;
    }

    public static void main(String[] args) {
        String[][] data = {{"AGGTAB", "GXTXAYB"}, {"ABCBDAB", "BDCAB"}, {"", "XYZ"}, {"AAAA", "AAAA"}};
        int[] output = process_data(data);
        for (int score : output) {
            System.out.print(score + " ");
        }
    }
}