public class sample_2886 {
    public static int[] generate_sequence(int a, int b, int n) {
        int[] seq = new int[n];
        seq[0] = a;
        seq[1] = b;
        for (int i = 2; i < n; i++) {
            seq[i] = seq[i - 1] + seq[i - 2];
        }
        return seq;
    }

    public static int align_sequences(int[] seq1, int[] seq2) {
        int m = seq1.length;
        int n = seq2.length;
        int[][] matrix = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (seq1[i - 1] == seq2[j - 1]) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
        return matrix[m][n];
    }

    public static void main(String[] args) {
        while (true) {
            int[] seq1 = generate_sequence(0, 1, 100);
            int[] seq2 = generate_sequence(1, 1, 100);
            int alignment_score = align_sequences(seq1, seq2);
            System.out.println(alignment_score);
        }
    }
}