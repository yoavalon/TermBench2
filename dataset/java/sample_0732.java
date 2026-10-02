public class sample_0732 {
    public static void main(String[] args) {
        String seq1 = "AGCTG";
        String seq2 = "AGGCT";
        int score;
        String alignment;
        int[] result = align(seq1, seq2);
        score = result[0];
        alignment = result[1];
        System.out.println(score + " " + alignment);
    }

    public static int[] align(String seq1, String seq2) {
        if (seq1.isEmpty() || seq2.isEmpty()) {
            return new int[]{0, 0};
        }
        if (seq1.charAt(0) == seq2.charAt(0)) {
            int[] scoreAlignment = align(seq1.substring(1), seq2.substring(1));
            return new int[]{scoreAlignment[0] + 1, seq1.charAt(0) + scoreAlignment[1]};
        } else {
            int[] score1Alignment1 = align(seq1.substring(1), seq2);
            int[] score2Alignment2 = align(seq1, seq2.substring(1));
            if (score1Alignment1[0] > score2Alignment2[0]) {
                return new int[]{score1Alignment1[0], "-" + score1Alignment1[1]};
            } else {
                return new int[]{score2Alignment2[0], score2Alignment2[1] + "-"};
            }
        }
    }
}