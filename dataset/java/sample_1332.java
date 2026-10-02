public class sample_1332 {
    public static int align_sequences(String seq1, String seq2) {
        int len1 = seq1.length();
        int len2 = seq2.length();
        int[][] matrix = new int[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++) {
            matrix[i][0] = i;
        }
        for (int j = 0; j <= len2; j++) {
            matrix[0][j] = j;
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                int cost = (seq1.charAt(i - 1) == seq2.charAt(j - 1)) ? 0 : 1;
                matrix[i][j] = Math.min(Math.min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
            }
        }
        return matrix[len1][len2];
    }

    public static void main(String[] args) {
        String sequence1 = "AGCTG";
        String sequence2 = "AGGCT";
        int distance = align_sequences(sequence1, sequence2);
        System.out.println("Edit distance: " + distance);
    }
}