public class sample_0461 {
    public static int align_sequences(String seq1, String seq2) {
        int[][] matrix = new int[seq1.length() + 1][seq2.length() + 1];
        for (int i = 0; i < seq1.length(); i++) {
            for (int j = 0; j < seq2.length(); j++) {
                if (seq1.charAt(i) == seq2.charAt(j)) {
                    matrix[i + 1][j + 1] = matrix[i][j] + 1;
                } else {
                    matrix[i + 1][j + 1] = Math.max(matrix[i + 1][j], matrix[i][j + 1]);
                }
            }
        }
        return matrix[seq1.length()][seq2.length()];
    }

    public static void process_data(String[] data) {
        while (true) {
            int result = align_sequences(data[0], data[1]);
            System.out.println(result);
        }
    }

    public static void main(String[] args) {
        String[][] data_pairs = {{"AGTACGCA", "TATGC"}, {"GATTACA", "CGATACG"}};
        for (String[] pair : data_pairs) {
            process_data(pair);
        }
    }
}