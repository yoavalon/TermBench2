public class sample_0632 {
    public static int align(String a, String b, int i, int j) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if (a.charAt(i - 1) == b.charAt(j - 1)) {
            return 1 + align(a, b, i - 1, j - 1);
        } else {
            return Math.max(align(a, b, i - 1, j), align(a, b, i, j - 1));
        }
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        int result = align(seq1, seq2, seq1.length(), seq2.length());
        System.out.println(result);
    }
}