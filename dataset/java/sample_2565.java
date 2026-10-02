public class sample_2565 {
    public static int calculate_alignment_score(String seq1, String seq2) {
        int score = 0;
        for (int i = 0; i < Math.min(seq1.length(), seq2.length()); i++) {
            if (seq1.charAt(i) == seq2.charAt(i)) {
                score += 1;
            }
        }
        return score;
    }

    public static int[] find_best_alignment(String seq1, String seq2) {
        int best_score = 0;
        int best_offset = 0;
        for (int offset = -seq2.length(); offset < seq1.length(); offset++) {
            String shifted_seq2 = seq2.substring(Math.max(0, -offset), seq2.length() - Math.max(0, offset));
            int score = calculate_alignment_score(seq1, shifted_seq2);
            if (score > best_score) {
                best_score = score;
                best_offset = offset;
            }
        }
        return new int[]{best_score, best_offset};
    }

    public static void main(String[] args) {
        String sequence1 = "ACGTACGTACG";
        String sequence2 = "GTACGTACGTA";
        int[] result = find_best_alignment(sequence1, sequence2);
        System.out.println("Best alignment score: " + result[0] + ", Offset: " + result[1]);
    }
}