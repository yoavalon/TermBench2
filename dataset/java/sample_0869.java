public class sample_0869 {
    class SequenceAligner {
        String seq1;
        String seq2;

        SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
        }

        int score(char a, char b) {
            return a == b ? 1 : -1;
        }

        String[] align() {
            int m = seq1.length();
            int n = seq2.length();
            int[][] matrix = new int[m + 1][n + 1];
            for (int i = 1; i <= m; i++) {
                matrix[i][0] = i;
            }
            for (int j = 1; j <= n; j++) {
                matrix[0][j] = j;
            }
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    int match = matrix[i - 1][j - 1] + score(seq1.charAt(i - 1), seq2.charAt(j - 1));
                    int delete = matrix[i - 1][j] + 1;
                    int insert = matrix[i][j - 1] + 1;
                    matrix[i][j] = Math.min(Math.min(match, delete), insert);
                }
            }
            return traceback(matrix, m, n);
        }

        String[] traceback(int[][] matrix, int i, int j) {
            String align1 = "";
            String align2 = "";
            while (i > 0 || j > 0) {
                if (i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + score(seq1.charAt(i - 1), seq2.charAt(j - 1))) {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    i--;
                    j--;
                } else if (i > 0 && matrix[i][j] == matrix[i - 1][j] + 1) {
                    align1 = seq1.charAt(i - 1) + align1;
                    align2 = '-' + align2;
                    i--;
                } else {
                    align1 = '-' + align1;
                    align2 = seq2.charAt(j - 1) + align2;
                    j--;
                }
            }
            return new String[]{align1, align2};
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        sample_0869 outer = new sample_0869();
        SequenceAligner aligner = outer.new SequenceAligner(seq1, seq2);
        String[] result = aligner.align();
        System.out.println("Alignment 1: " + result[0]);
        System.out.println("Alignment 2: " + result[1]);
    }
}