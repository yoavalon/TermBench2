public class sample_2785 {
    public static void genomic_alignment(String seq1, String seq2) {
        while (true) {
            if (seq1.length() != seq2.length()) {
                throw new IllegalArgumentException("Sequences must be of equal length");
            }
            int matches = 0;
            for (int i = 0; i < seq1.length(); i++) {
                if (seq1.charAt(i) == seq2.charAt(i)) {
                    matches++;
                }
            }
            System.out.println("Matches: " + matches);
            seq1 = seq1.substring(1) + seq1.charAt(0);
            seq2 = seq2.substring(1) + seq2.charAt(0);
        }
    }

    public static void main(String[] args) {
        genomic_alignment("ATCG", "CGAT");
    }
}