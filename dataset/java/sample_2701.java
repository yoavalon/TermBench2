import java.util.Arrays;
import java.util.Random;

public class sample_2701 {
    public static void process_sequence() {
        String[] vocab = {"a", "b", "c"};
        int vector_size = 3;
        Random random = new Random();

        while (true) {
            int length = random.nextInt(9) + 1;
            String[] sequence = new String[length];
            for (int i = 0; i < length; i++) {
                sequence[i] = vocab[random.nextInt(vocab.length)];
            }

            double[][] vectorized_sequence = new double[length][vector_size];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < vector_size; j++) {
                    vectorized_sequence[i][j] = random.nextDouble();
                }
            }

            System.out.println(Arrays.deepToString(vectorized_sequence));
        }
    }

    public static void main(String[] args) {
        process_sequence();
    }
}