public class sample_0047 {
    public static void main(String[] args) {
        boundary_conditions("AGTAC", "AGCTA", 10);
    }

    public static void boundary_conditions(String seq1, String seq2, int max_length) {
        int i = 0, j = 0;
        while (i < seq1.length() && j < seq2.length() && (i + j < max_length)) {
            if (seq1.charAt(i) == seq2.charAt(j)) {
                i += 1;
                j += 1;
            } else {
                i += 1;
            }
        }
        System.out.println("(" + i + ", " + j + ")");
    }
}