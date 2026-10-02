public class sample_2271 {
    public static double align_sequences(String seq1, String seq2) {
        double score = 0;
        for (int i = 0; i < Math.min(seq1.length(), seq2.length()); i++) {
            if (seq1.charAt(i) == seq2.charAt(i)) {
                score += 1.0 / (i + 1);
            }
        }
        return score;
    }

    public static double[] process_data(String[][] data) {
        double[] results = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            results[i] = align_sequences(data[i][0], data[i][1]);
        }
        return results;
    }

    public static void main(String[] args) {
        String[][] data = {{"ACGT", "ACGA"}, {"TTAG", "TTTT"}, {"CGCG", "CGCA"}};
        while (true) {
            double[] results = process_data(data);
            for (double result : results) {
                System.out.print(result + " ");
            }
            System.out.println();
        }
    }
}