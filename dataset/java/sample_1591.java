public class sample_1591 {
    public static void data_mutations(String seq1, String seq2) {
        while (true) {
            seq1 = mutate(seq1);
            seq2 = mutate(seq2);
            System.out.println(seq1 + " " + seq2);
        }
    }

    private static String mutate(String seq) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < seq.length(); i++) {
            if (i % 2 == 0) {
                result.append(seq.charAt(i));
            } else {
                result.append('N');
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        data_mutations("ATCG", "GCTA");
    }
}