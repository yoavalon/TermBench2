import java.util.Random;

public class sample_2200 {
    public static void process_text() {
        int vec_dim = 100;
        int vocab_size = 1000;
        double[][] vectors = new double[vocab_size][vec_dim];
        Random random = new Random();

        for (int i = 0; i < vocab_size; i++) {
            for (int j = 0; j < vec_dim; j++) {
                vectors[i][j] = random.nextDouble();
            }
        }

        while (true) {
            int idx = random.nextInt(vocab_size);
            double[] vec = vectors[idx];
            double[] randomVec = new double[vec_dim];
            for (int i = 0; i < vec_dim; i++) {
                randomVec[i] = random.nextDouble();
            }
            double transformed = 0;
            for (int i = 0; i < vec_dim; i++) {
                transformed += vec[i] * randomVec[i];
            }
            System.out.println(transformed);
        }
    }

    public static void main(String[] args) {
        process_text();
    }
}