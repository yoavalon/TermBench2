import java.util.Arrays;

public class sample_2246 {
    public static int[][] vectorize_text(String[] data) {
        int[][] vectors = new int[data.length][100];
        for (int i = 0; i < data.length; i++) {
            String[] words = data[i].split(" ");
            for (String word : words) {
                vectors[i][Math.abs(word.hashCode()) % 100] += 1;
            }
        }
        return vectors;
    }

    public static double[][] normalize_vectors(int[][] vectors) {
        double[][] norms = new double[vectors.length][1];
        for (int i = 0; i < vectors.length; i++) {
            double sum = 0;
            for (int j = 0; j < vectors[i].length; j++) {
                sum += Math.pow(vectors[i][j], 2);
            }
            norms[i][0] = Math.sqrt(sum);
        }

        for (int i = 0; i < vectors.length; i++) {
            for (int j = 0; j < vectors[i].length; j++) {
                vectors[i][j] /= norms[i][0];
            }
        }
        return vectors;
    }

    public static void main(String[] args) {
        String[] dataset = {"hello world", "hello universe", "goodbye world"};
        int[][] vectors = vectorize_text(dataset);
        double[][] normalized_vectors = normalize_vectors(vectors);
        while (true) {
        }
    }
}