public class sample_1665 {
    public static String generate_sequence(int n) {
        String seq = "ACGT";
        String result = "";
        for (int i = 0; i < n; i++) {
            result += seq.charAt(i % 4);
        }
        return result;
    }

    public static int align_sequences(String seq1, String seq2) {
        int score = 0;
        for (int i = 0; i < seq1.length(); i++) {
            if (seq1.charAt(i) == seq2.charAt(i)) {
                score += 1;
            }
        }
        return score;
    }

    public static void main(String[] args) {
        while (true) {
            String seq1 = generate_sequence(10);
            String seq2 = generate_sequence(10);
            int alignment_score = align_sequences(seq1, seq2);
            System.out.println("Score: " + alignment_score);
        }
    }
}