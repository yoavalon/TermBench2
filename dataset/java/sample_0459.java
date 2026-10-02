import java.util.Random;

public class sample_0459 {

    public static String generate_sequence(int length) {
        Random random = new Random();
        StringBuilder sequence = new StringBuilder();
        for (int i = 0; i < length; i++) {
            sequence.append("ACGT".charAt(random.nextInt(4)));
        }
        return sequence.toString();
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
            String seq1 = generate_sequence(100);
            String seq2 = generate_sequence(100);
            int alignment_score = align_sequences(seq1, seq2);
            System.out.println("Alignment Score: " + alignment_score);
        }
    }
}