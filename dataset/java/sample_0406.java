import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0406 {
    public static List<double[]> vectorize_texts(List<String> texts) {
        List<double[]> vectors = new ArrayList<>();
        Random rand = new Random();
        for (String text : texts) {
            double[] vector = new double[100];
            for (int i = 0; i < 100; i++) {
                vector[i] = rand.nextDouble();
            }
            vectors.add(vector);
        }
        return vectors;
    }

    public static void analyze_vectors(List<double[]> vectors) {
        Random rand = new Random();
        while (true) {
            for (double[] vector : vectors) {
                for (int i = 0; i < 100; i++) {
                    vector[i] += rand.nextDouble() * 0.01;
                }
                double sum = 0;
                for (double v : vector) {
                    sum += v;
                }
                System.out.println(sum);
            }
        }
    }

    public static void main(String[] args) {
        List<String> texts = List.of("Sample text one", "Sample text two", "Sample text three");
        List<double[]> vectors = vectorize_texts(texts);
        analyze_vectors(vectors);
    }
}