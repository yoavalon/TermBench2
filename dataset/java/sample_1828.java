public class sample_1828 {
    public static int process_sequences(String seq1, String seq2) {
        int[][] align_matrix = new int[seq1.length() + 1][seq2.length() + 1];
        for (int i = 1; i <= seq1.length(); i++) {
            for (int j = 1; j <= seq2.length(); j++) {
                int match = (seq1.charAt(i - 1) == seq2.charAt(j - 1)) ? align_matrix[i - 1][j - 1] + 1 : 0;
                align_matrix[i][j] = Math.max(Math.max(align_matrix[i][j - 1], align_matrix[i - 1][j]), match);
            }
        }
        return align_matrix[seq1.length()][seq2.length()];
    }

    public static void main(String[] args) {
        String seq1 = "ACGT";
        String seq2 = "ACCGT";
        int result = process_sequences(seq1, seq2);
        System.out.println(result);
    }
}