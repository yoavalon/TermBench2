public class sample_0768 {
    public static int align(String seq1, String seq2) {
        if (seq1.isEmpty() || seq2.isEmpty()) {
            return 0;
        }
        if (seq1.charAt(0) == seq2.charAt(0)) {
            return 1 + align(seq1.substring(1), seq2.substring(1));
        } else {
            int align1 = align(seq1.substring(1), seq2);
            int align2 = align(seq1, seq2.substring(1));
            return Math.max(align1, align2);
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        int result = align(seq1, seq2);
        System.out.println(result);
    }
}