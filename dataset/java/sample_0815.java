public class sample_0815 {

    class GenomicAligner {
        String seq1;
        String seq2;
        int[][] matrix;

        GenomicAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.matrix = new int[seq1.length() + 1][seq2.length() + 1];
        }

        private int _score(char a, char b) {
            return a == b ? 1 : -1;
        }

        private void _fill_matrix() {
            for (int i = 1; i <= seq1.length(); i++) {
                for (int j = 1; j <= seq2.length(); j++) {
                    int match = matrix[i - 1][j - 1] + _score(seq1.charAt(i - 1), seq2.charAt(j - 1));
                    int delete = matrix[i - 1][j] - 1;
                    int insert = matrix[i][j - 1] - 1;
                    matrix[i][j] = Math.max(match, Math.max(delete, insert));
                }
            }
        }

        private Pair _traceback(int i, int j) {
            if (i == 0 || j == 0) {
                return new Pair("", "");
            }
            if (matrix[i][j] == matrix[i - 1][j - 1] + _score(seq1.charAt(i - 1), seq2.charAt(j - 1))) {
                Pair s = _traceback(i - 1, j - 1);
                return new Pair(seq1.charAt(i - 1) + s.first, seq2.charAt(j - 1) + s.second);
            } else if (matrix[i][j] == matrix[i - 1][j] - 1) {
                Pair s = _traceback(i - 1, j);
                return new Pair(seq1.charAt(i - 1) + s.first, "-" + s.second);
            } else {
                Pair s = _traceback(i, j - 1);
                return new Pair("-" + s.first, seq2.charAt(j - 1) + s.second);
            }
        }

        public Pair align() {
            _fill_matrix();
            return _traceback(seq1.length(), seq2.length());
        }
    }

    static class Pair {
        String first;
        String second;

        Pair(String first, String second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
        String seq1 = "ACGTGACGTG";
        String seq2 = "GTCGTGTCG";
        sample_0815 sample = new sample_0815();
        GenomicAligner aligner = sample.new GenomicAligner(seq1, seq2);
        Pair aligned = aligner.align();
        System.out.println("Aligned Sequence 1: " + aligned.first);
        System.out.println("Aligned Sequence 2: " + aligned.second);
    }
}