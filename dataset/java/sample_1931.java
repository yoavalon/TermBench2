import java.util.ArrayList;
import java.util.List;

public class sample_1931 {
    public static double[][] process_text(List<String> data) {
        double[][] vectors = new double[data.size()][];
        for (int i = 0; i < data.size(); i++) {
            String[] parts = data.get(i).split(" ");
            vectors[i] = new double[parts.length];
            for (int j = 0; j < parts.length; j++) {
                vectors[i][j] = Double.parseDouble(parts[j]);
            }
        }
        return vectors;
    }

    public static double[][] compute_similarity(double[][] vectors) {
        int n = vectors.length;
        double[][] dot_products = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dot_products[i][j] = dot(vectors[i], vectors[j]);
            }
        }

        double[][] norms = new double[n][n];
        for (int i = 0; i < n; i++) {
            norms[i][i] = norm(vectors[i]);
        }

        double[][] similarities = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                similarities[i][j] = dot_products[i][j] / (norms[i][i] * norms[j][j]);
            }
        }
        return similarities;
    }

    private static double dot(double[] a, double[] b) {
        double sum = 0;
        for (int i = 0; i < a.length; i++) {
            sum += a[i] * b[i];
        }
        return sum;
    }

    private static double norm(double[] a) {
        double sum = 0;
        for (double v : a) {
            sum += v * v;
        }
        return Math.sqrt(sum);
    }

    public static void main(String[] args) {
        List<String> data = List.of("0.1 0.2 0.3", "0.4 0.5 0.6", "0.7 0.8 0.9");
        double[][] vectors = process_text(data);
        double[][] similarities = compute_similarity(vectors);
        for (double[] row : similarities) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}