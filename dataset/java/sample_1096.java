public class sample_1096 {
    public static void main(String[] args) {
        String x = "GATTACA";
        String y = "GACTATA";
        while (true) {
            int[] result = align(x, y);
            System.out.println(result[1]);
            System.out.println(result[2]);
        }
    }

    public static int[] align(String seq1, String seq2) {
        if (seq1.isEmpty() || seq2.isEmpty()) {
            return new int[]{0, seq1, seq2};
        }
        if (seq1.charAt(0) == seq2.charAt(0)) {
            int[] match = align(seq1.substring(1), seq2.substring(1));
            return new int[]{match[0] + 1, seq1.charAt(0) + match[1], seq2.charAt(0) + match[2]};
        } else {
            int[] m1 = align(seq1.substring(1), seq2);
            int[] m2 = align(seq1, seq2.substring(1));
            if (m1[0] > m2[0]) {
                return new int[]{m1[0], seq1.charAt(0) + m1[1], '-' + m1[2]};
            } else {
                return new int[]{m2[0], '-' + m2[1], seq2.charAt(0) + m2[2]};
            }
        }
    }
}