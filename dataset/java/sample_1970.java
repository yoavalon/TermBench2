import java.util.Random;

public class sample_1970 {
    public static double[][] process_data(String[] data) {
        double[][] vectors = new double[data.length][100];
        Random rand = new Random();
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < 100; j++) {
                vectors[i][j] = rand.nextDouble();
            }
        }
        return vectors;
    }

    public static double analyze_vectors(double[][] vectors) {
        double[] mean_vector = new double[100];
        for (int j = 0; j < 100; j++) {
            for (int i = 0; i < vectors.length; i++) {
                mean_vector[j] += vectors[i][j];
            }
            mean_vector[j] /= vectors.length;
        }

        double precision_loss = 0.0;
        for (int i = 0; i < vectors.length; i++) {
            for (int j = 0; j < 100; j++) {
                precision_loss += Math.abs(vectors[i][j] - mean_vector[j]);
            }
        }
        precision_loss /= vectors.length * 100;
        return precision_loss;
    }

    public static void main(String[] args) {
        String[] data = new String[1000];
        for (int i = 0; i < 1000; i++) {
            data[i] = "sample text";
        }
        double[][] vectors = process_data(data);
        double loss = analyze_vectors(vectors);
        System.out.println("Precision Loss: " + loss);
    }
}