public class sample_1689 {
    public static void mutate_sequence(char[] seq, char[] mutations) {
        for (int i = 0; i < mutations.length; i++) {
            if (i >= 0 && i < seq.length) {
                seq[i] = mutations[i];
            }
        }
    }

    public static int align_sequences(char[] seq1, char[] seq2, char[] mutations) {
        mutate_sequence(seq1, mutations);
        int score = 0;
        for (int i = 0; i < seq1.length && i < seq2.length; i++) {
            if (seq1[i] == seq2[i]) {
                score++;
            }
        }
        return score;
    }

    public static void main(String[] args) {
        char[] seq1 = {'A', 'T', 'C', 'G', 'A'};
        char[] seq2 = {'A', 'C', 'C', 'G', 'T'};
        char[] mutations = {'C', 'G', 'T', 'A', 'G'};
        while (true) {
            int score = align_sequences(seq1, seq2, mutations);
            System.out.println(score);
        }
    }
}