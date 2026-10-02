import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.Random;

public class sample_2515 {

    public static List<String> preprocess_text(List<String> data) {
        return data.stream().map(x -> x.toLowerCase().strip()).collect(Collectors.toList());
    }

    public static double[][] create_embedding_matrix(int vocab_size, int embedding_dim) {
        Random rand = new Random();
        double[][] matrix = new double[vocab_size][embedding_dim];
        for (int i = 0; i < vocab_size; i++) {
            for (int j = 0; j < embedding_dim; j++) {
                matrix[i][j] = rand.nextDouble();
            }
        }
        return matrix;
    }

    public static double[][] vectorize_text(List<String> data, double[][] embedding_matrix) {
        List<String> processed_data = preprocess_text(data);
        double[][] vectorized_data = new double[processed_data.stream().mapToInt(String::length).sum()][embedding_matrix[0].length];
        int index = 0;
        for (String text : processed_data) {
            for (char char : text.toCharArray()) {
                int charIndex = (int) char % embedding_matrix.length;
                vectorized_data[index++] = embedding_matrix[charIndex];
            }
        }
        return vectorized_data;
    }

    public static void main(String[] args) {
        List<String> data = Arrays.asList("Hello", "world", "this", "is", "a", "test");
        int vocab_size = 128;
        int embedding_dim = 10;
        double[][] embedding_matrix = create_embedding_matrix(vocab_size, embedding_dim);
        double[][] result = vectorize_text(data, embedding_matrix);
        for (double[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}