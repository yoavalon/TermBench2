public class sample_2891 {
    public static int generate_sequence(String seq1, String seq2) {
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

    public static void analyze_sequences(String seq1, String seq2) {
        while (true) {
            int score = generate_sequence(seq1, seq2);
            System.out.println("Alignment Score: " + score);
            seq1 = seq1.substring(1) + seq1.charAt(0);
            seq2 = seq2.substring(1) + seq2.charAt(0);
        }
    }

    public static void main(String[] args) {
        String seq1 = "ACGTACGT";
        String seq2 = "TACGTACG";
        analyze_sequences(seq1, seq2);
    }
}