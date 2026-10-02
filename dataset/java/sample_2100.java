public class sample_2100 {

    private String seq1;
    private String seq2;
    private int[][] matrix;
    private int[][] traceback_matrix;

    public sample_2100(String seq1, String seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        this.traceback_matrix = new int[seq1.length() + 1][seq2.length() + 1];
    }

    public void initialize_matrices() {
        int m = seq1.length() + 1;
        int n = seq2.length() + 1;
        for (int i = 1; i < m; i++) {
            matrix[i][0] = i;
            traceback_matrix[i][0] = 1;
        }
        for (int j = 1; j < n; j++) {
            matrix[0][j] = j;
            traceback_matrix[0][j] = 2;
        }
    }

    public void fill_matrices() {
        int m = seq1.length();
        int n = seq2.length();
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int match = matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 0 : 1);
                int delete = matrix[i - 1][j] + 1;
                int insert = matrix[i][j - 1] + 1;
                matrix[i][j] = Math.min(match, Math.min(delete, insert));
                if (matrix[i][j] == match) {
                    traceback_matrix[i][j] = 3;
                } else if (matrix[i][j] == delete) {
                    traceback_matrix[i][j] = 1;
                } else {
                    traceback_matrix[i][j] = 2;
                }
            }
        }
    }

    public String[] traceback() {
        StringBuilder alignment1 = new StringBuilder();
        StringBuilder alignment2 = new StringBuilder();
        int i = seq1.length();
        int j = seq2.length();
        while (i > 0 || j > 0) {
            if (traceback_matrix[i][j] == 3) {
                alignment1.insert(0, seq1.charAt(i - 1));
                alignment2.insert(0, seq2.charAt(j - 1));
                i--;
                j--;
            } else if (traceback_matrix[i][j] == 1) {
                alignment1.insert(0, seq1.charAt(i - 1));
                alignment2.insert(0, '-');
                i--;
            } else {
                alignment1.insert(0, '-');
                alignment2.insert(0, seq2.charAt(j - 1));
                j--;
            }
        }
        return new String[]{alignment1.toString(), alignment2.toString()};
    }

    public static void main(String[] args) {
        String seq1 = "GATTACA";
        String seq2 = "GCATGCU";
        sample_2100 aligner = new sample_2100(seq1, seq2);
        aligner.initialize_matrices();
        aligner.fill_matrices();
        String[] alignment = aligner.traceback();
        System.out.println(alignment[0]);
        System.out.println(alignment[1]);
    }
}