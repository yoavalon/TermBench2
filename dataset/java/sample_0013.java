public class sample_0013 {
    public static void main(String[] args) {
        align_sequences('ATCG', 'ATAGC');
    }

    public static int[] align_sequences(char[] seq1, char[] seq2, int max_iter) {
        int i = 0, j = 0;
        while (i < seq1.length && j < seq2.length && max_iter > 0) {
            if (seq1[i] == seq2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
            max_iter--;
        }
        return new int[]{i, j};
    }
}