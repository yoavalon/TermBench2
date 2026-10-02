import java.util.Random;

public class sample_1730 {

    public static String generate_sequence(int length) {
        Random random = new Random();
        StringBuilder sequence = new StringBuilder();
        for (int i = 0; i < length; i++) {
            sequence.append("ATCG".charAt(random.nextInt(4)));
        }
        return sequence.toString();
    }

    public static int align_sequences(String seq1, String seq2) {
        int[][] matrix = new int[seq1.length() + 1][seq2.length() + 1];
        for (int i = 1; i <= seq1.length(); i++) {
            for (int j = 1; j <= seq2.length(); j++) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
        return matrix[seq1.length()][seq2.length()];
    }

    public static String mutate_sequence(String seq) {
        Random random = new Random();
        char[] seqArray = seq.toCharArray();
        for (int i = 0; i < seqArray.length; i++) {
            if (random.nextDouble() < 0.1) {
                seqArray[i] = "ATCG".charAt(random.nextInt(4));
            }
        }
        return new String(seqArray);
    }

    static class SequenceAligner {

        private String seq1;
        private String seq2;

        public SequenceAligner(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
        }

        public void update_sequences() {
            this.seq1 = mutate_sequence(this.seq1);
            this.seq2 = mutate_sequence(this.seq2);
        }

        public void run_alignment() {
            while (true) {
                int alignment_score = align_sequences(this.seq1, this.seq2);
                System.out.println("Alignment Score: " + alignment_score);
                this.update_sequences();
            }
        }
    }

    public static void main(String[] args) {
        String seq1 = generate_sequence(100);
        String seq2 = generate_sequence(100);
        SequenceAligner aligner = new SequenceAligner(seq1, seq2);
        aligner.run_alignment();
    }
}