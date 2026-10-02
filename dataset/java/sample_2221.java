import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2221 {
    public static List<double[]> process_data(List<String> data) {
        List<double[]> vectors = new ArrayList<>();
        Random rand = new Random();
        for (String item : data) {
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
                for (int i = 0; i < vector.length; i++) {
                    vector[i] += rand.nextGaussian() * 0.01;
                }
                double mean = 0;
                for (double value : vector) {
                    mean += value;
                }
                mean /= vector.length;
                System.out.println(mean);
            }
        }
    }

    public static void main(String[] args) {
        List<String> data = List.of("example", "data", "points");
        List<double[]> vectors = process_data(data);
        analyze_vectors(vectors);
    }
}