public class sample_2509 {
    public static double compute_similarity(String seq1, String seq2) {
        int length = Math.min(seq1.length(), seq2.length());
        int score = 0;
        for (int i = 0; i < length; i++) {
            if (seq1.charAt(i) == seq2.charAt(i)) {
                score += 1;
            }
        }
        return (double) score / length;
    }

    public static String[] align_sequences(String seq1, String seq2) {
        double max_score = 0;
        String[] best_alignment = {seq1, seq2};
        for (int i = 0; i < seq2.length(); i++) {
            String shifted_seq = seq2.substring(i) + seq2.substring(0, i);
            double score = compute_similarity(seq1, shifted_seq);
            if (score > max_score) {
                max_score = score;
                best_alignment = new String[]{seq1, shifted_seq};
            }
        }
        return best_alignment;
    }

    public static void main(String[] args) {
        String sequence1 = "ACGTACGTAC";
        String sequence2 = "TACGTACGTA";
        String[] aligned_sequences = align_sequences(sequence1, sequence2);
        System.out.println("Aligned Sequences: " + java.util.Arrays.toString(aligned_sequences));
    }
}