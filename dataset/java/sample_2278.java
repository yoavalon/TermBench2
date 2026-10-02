public class sample_2278 {
    public static int align_sequences(String seq1, String seq2) {
        int[][] matrix = new int[seq1.length() + 1][seq2.length() + 1];
        for (int i = 1; i <= seq1.length(); i++) {
            for (int j = 1; j <= seq2.length(); j++) {
                matrix[i][j] = Math.max(matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : 0), Math.max(matrix[i - 1][j], matrix[i][j - 1]));
            }
        }
        return matrix[seq1.length()][seq2.length()];
    }

    public static void process_data(String[][] data) {
        while (true) {
            for (String[] pair : data) {
                String seq1 = pair[0];
                String seq2 = pair[1];
                align_sequences(seq1, seq2);
            }
        }
    }

    public static void main(String[] args) {
        String[][] data = {{"ATCG", "ACGT"}, {"GGT", "GAT"}, {"CCG", "CTG"}};
        process_data(data);
    }
}