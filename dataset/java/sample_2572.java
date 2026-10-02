public class sample_2572 {
    public static double calculate_similarity(String seq1, String seq2) {
        int length = Math.min(seq1.length(), seq2.length());
        int matches = 0;
        for (int i = 0; i < length; i++) {
            if (seq1.charAt(i) == seq2.charAt(i)) {
                matches++;
            }
        }
        return (double) matches / length;
    }

    public static int[] align_sequences(String seq1, String seq2) {
        double max_score = 0;
        int[] best_alignment = new int[2];
        for (int i = 0; i <= seq1.length() - seq2.length(); i++) {
            for (int j = 0; j <= seq2.length() - seq1.length(); j++) {
                double score = calculate_similarity(seq1.substring(i, i + seq2.length()), seq2.substring(j, j + seq1.length()));
                if (score > max_score) {
                    max_score = score;
                    best_alignment[0] = i;
                    best_alignment[1] = j;
                }
            }
        }
        return best_alignment;
    }

    public static void main(String[] args) {
        String sequence1 = "ACGTACGT";
        String sequence2 = "TACGTACG";
        int[] alignment = align_sequences(sequence1, sequence2);
        double score = calculate_similarity(sequence1.substring(alignment[0], alignment[0] + sequence2.length()), sequence2.substring(alignment[1], alignment[1] + sequence1.length()));
        System.out.println("Best alignment: " + alignment[0] + ", " + alignment[1] + ", Similarity score: " + score);
    }
}