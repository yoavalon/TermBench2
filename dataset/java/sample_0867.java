public class sample_0867 {
    private String seq1;
    private String seq2;
    private int[][] matrix;
    private String[] result;

    public Alignment(String seq1, String seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        fillMatrix();
        traceback();
    }

    private void fillMatrix() {
        for (int i = 1; i <= seq1.length(); i++) {
            for (int j = 1; j <= seq2.length(); j++) {
                int match = (seq1.charAt(i - 1) == seq2.charAt(j - 1)) ? matrix[i - 1][j - 1] + 1 : 0;
                int delete = matrix[i - 1][j] - 1;
                int insert = matrix[i][j - 1] - 1;
                matrix[i][j] = Math.max(match, Math.max(delete, insert));
            }
        }
    }

    private void traceback() {
        int i = seq1.length();
        int j = seq2.length();
        String align1 = "";
        String align2 = "";
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && (matrix[i][j] == matrix[i - 1][j - 1] + 1) && (seq1.charAt(i - 1) == seq2.charAt(j - 1))) {
                align1 = seq1.charAt(i - 1) + align1;
                align2 = seq2.charAt(j - 1) + align2;
                i--;
                j--;
            } else if (i > 0 && (j == 0 || matrix[i][j] == matrix[i - 1][j] - 1)) {
                align1 = seq1.charAt(i - 1) + align1;
                align2 = '-' + align2;
                i--;
            } else {
                align1 = '-' + align1;
                align2 = seq2.charAt(j - 1) + align2;
                j--;
            }
        }
        this.result = new String[]{align1, align2};
    }

    public static void main(String[] args) {
        String seq1 = "AGTACGCA";
        String seq2 = "GTTAC";
        Alignment alignment = new Alignment(seq1, seq2);
        System.out.println("Sequence 1: " + alignment.result[0]);
        System.out.println("Sequence 2: " + alignment.result[1]);
    }
}