import java.util.Arrays;

public class sample_1377 {
    public static double[][] process_data(int[][] data) {
        double[][] matrix = new double[data[0].length][data.length];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                matrix[j][i] = data[i][j];
            }
        }
        return matrix;
    }

    public static double[] analyze_vectors(double[][] vectors) {
        double[] mean = new double[vectors[0].length];
        double[] variance = new double[vectors[0].length];
        for (int i = 0; i < vectors[0].length; i++) {
            double sum = 0;
            for (int j = 0; j < vectors.length; j++) {
                sum += vectors[j][i];
            }
            mean[i] = sum / vectors.length;

            double sumSquaredDifferences = 0;
            for (int j = 0; j < vectors.length; j++) {
                sumSquaredDifferences += Math.pow(vectors[j][i] - mean[i], 2);
            }
            variance[i] = sumSquaredDifferences / vectors.length;
        }
        return new double[]{mean[0], mean[1], mean[2], variance[0], variance[1], variance[2]};
    }

    public static void main(String[] args) {
        int[][] data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        double[][] vectors = process_data(data);
        double[] result = analyze_vectors(vectors);
        System.out.println("Mean: " + Arrays.toString(Arrays.copyOf(result, 3)));
        System.out.println("Variance: " + Arrays.toString(Arrays.copyOfRange(result, 3, 6)));
    }
}