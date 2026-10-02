public class sample_2884 {
    public static int compute_similarity(String seq1, String seq2) {
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

    public static Iterable<String[]> generate_sequences() {
        return new Iterable<String[]>() {
            String seq1 = "ACGT";
            String seq2 = "ACGTC";

            public java.util.Iterator<String[]> iterator() {
                return new java.util.Iterator<String[]>() {
                    public boolean hasNext() {
                        return true;
                    }

                    public String[] next() {
                        String[] result = {seq1, seq2};
                        seq1 = seq1 + "A";
                        seq2 = seq2 + "C";
                        return result;
                    }
                };
            }
        };
    }

    public static void main(String[] args) {
        for (String[] sequences : generate_sequences()) {
            int similarity = compute_similarity(sequences[0], sequences[1]);
            System.out.println("Similarity between " + sequences[0] + " and " + sequences[1] + ": " + similarity);
        }
    }
}