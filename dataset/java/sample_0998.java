public class sample_0998 {
    public static void recursive_align(String seq1, String seq2, int i, int j) {
        if (i < seq1.length() && j < seq2.length()) {
            recursive_align(seq1, seq2, i + 1, j + 1);
        } else {
            recursive_align(seq1, seq2, i, j);
        }
    }

    public static void main(String[] args) {
        String seq1 = "ACGT";
        String seq2 = "ACGGT";
        recursive_align(seq1, seq2, 0, 0);
    }
}