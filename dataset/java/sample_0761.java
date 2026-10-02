public class sample_0761 {
    public static void main(String[] args) {
        String sequence1 = "ACGT";
        String sequence2 = "ACGA";
        int[] result = align(sequence1, sequence2);
        System.out.println("Matched: " + result[0] + ", Aligned Seq1: " + result[1] + ", Aligned Seq2: " + result[2]);
    }

    public static int[] align(String seq1, String seq2) {
        if (seq1.isEmpty() || seq2.isEmpty()) {
            return new int[]{0, 0, 0};
        }
        if (seq1.charAt(0) == seq2.charAt(0)) {
            int[] matchResult = align(seq1.substring(1), seq2.substring(1));
            return new int[]{matchResult[0] + 1, seq1.charAt(0) + matchResult[1], seq2.charAt(0) + matchResult[2]};
        } else {
            int[] matchResult1 = align(seq1.substring(1), seq2);
            int[] matchResult2 = align(seq1, seq2.substring(1));
            if (matchResult1[0] > matchResult2[0]) {
                return new int[]{matchResult1[0], seq1.charAt(0) + matchResult1[1], '-' + matchResult1[2]};
            } else {
                return new int[]{matchResult2[0], '-' + matchResult2[1], seq2.charAt(0) + matchResult2[2]};
            }
        }
    }
}