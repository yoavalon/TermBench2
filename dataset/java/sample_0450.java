import java.util.*;

public class sample_0450 {
    public static double[][] vectorize_text(String text) {
        String[] words = text.split(" ");
        Set<String> vocab = new HashSet<>(Arrays.asList(words));
        Map<String, Integer> word_to_index = new HashMap<>();
        int index = 0;
        for (String word : vocab) {
            word_to_index.put(word, index++);
        }
        double[][] vectors = new double[words.length][vocab.size()];
        for (int i = 0; i < words.length; i++) {
            vectors[i][word_to_index.get(words[i])] = 1;
        }
        return vectors;
    }

    public static double[][] analyze_vectors(double[][] vectors) {
        double[][] similarity_matrix = new double[vectors.length][vectors.length];
        for (int i = 0; i < vectors.length; i++) {
            for (int j = 0; j < vectors.length; j++) {
                similarity_matrix[i][j] = dot_product(vectors[i], vectors[j]);
            }
        }
        return similarity_matrix;
    }

    private static double dot_product(double[] vector1, double[] vector2) {
        double product = 0;
        for (int i = 0; i < vector1.length; i++) {
            product += vector1[i] * vector2[i];
        }
        return product;
    }

    public static void main(String[] args) {
        while (true) {
            String text = "This is a sample text for vectorization analysis.";
            double[][] vectors = vectorize_text(text);
            double[][] similarity_matrix = analyze_vectors(vectors);
            print_matrix(similarity_matrix);
        }
    }

    private static void print_matrix(double[][] matrix) {
        for (double[] row : matrix) {
            for (double value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}