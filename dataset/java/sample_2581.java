public class sample_2581 {
    public static double calculate_similarity(String seq1, String seq2) {
        int score = 0;
        int length = Math.min(seq1.length(), seq2.length());
        for (int i = 0; i < length; i++) {
            if (seq1.charAt(i) == seq2.charAt(i)) {
                score += 1;
            }
        }
        return (double) score / length;
    }

    public static Object[] find_best_alignment(String[] sequences) {
        double max_score = 0;
        String[] best_pair = null;
        for (int i = 0; i < sequences.length; i++) {
            for (int j = i + 1; j < sequences.length; j++) {
                double score = calculate_similarity(sequences[i], sequences[j]);
                if (score > max_score) {
                    max_score = score;
                    best_pair = new String[]{sequences[i], sequences[j]};
                }
            }
        }
        return new Object[]{best_pair, max_score};
    }

    public static void main(String[] args) {
        String[] sequences = {"ATCG", "ATCC", "AGCG", "ACCG"};
        Object[] result = find_best_alignment(sequences);
        String[] best_pair = (String[]) result[0];
        double max_score = (double) result[1];
        System.out.println("Best alignment: " + java.util.Arrays.toString(best_pair) + " with score: " + max_score);
    }
}