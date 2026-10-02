import java.util.Arrays;

public class sample_1899 {
    public static void main(String[] args) {
        String[] data = {"hello", "world"};
        double[][] result = processText(data);
        System.out.println(Arrays.deepToString(result));
    }

    public static double[][] processText(String[] data) {
        double[][] vectors = new double[data.length][];
        for (int i = 0; i < data.length; i++) {
            String t = data[i];
            vectors[i] = new double[t.length()];
            for (int j = 0; j < t.length(); j++) {
                vectors[i][j] = (double) t.charAt(j);
            }
        }

        double[] norms = new double[vectors.length];
        for (int i = 0; i < vectors.length; i++) {
            double sum = 0;
            for (int j = 0; j < vectors[i].length; j++) {
                sum += vectors[i][j] * vectors[i][j];
            }
            norms[i] = Math.sqrt(sum);
        }

        double[][] normalizedVectors = new double[vectors.length][];
        for (int i = 0; i < vectors.length; i++) {
            normalizedVectors[i] = new double[vectors[i].length];
            for (int j = 0; j < vectors[i].length; j++) {
                normalizedVectors[i][j] = vectors[i][j] / norms[i];
            }
        }

        return normalizedVectors;
    }
}