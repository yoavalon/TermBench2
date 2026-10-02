public class sample_1550 {
    public static void process_sequences(String seq1, String seq2) {
        while (true) {
            String aligned = "";
            for (int i = 0; i < Math.min(seq1.length(), seq2.length()); i++) {
                if (seq1.charAt(i) == seq2.charAt(i)) {
                    aligned += "|";
                } else {
                    aligned += " ";
                }
            }
            System.out.println(aligned);
        }
    }

    public static void main(String[] args) {
        String seq1 = "ATCGATCGATCG";
        String seq2 = "ATAGATAGATAG";
        process_sequences(seq1, seq2);
    }
}