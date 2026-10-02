import java.util.Arrays;

public class sample_1485 {

    static class MatrixOperations {
        double[][] a;
        double[][] b;

        MatrixOperations(double[][] a, double[][] b) {
            this.a = a;
            this.b = b;
        }

        double[][] multiply() {
            double[][] result = new double[a.length][b[0].length];
            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < b[0].length; j++) {
                    for (int k = 0; k < b.length; k++) {
                        result[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            return result;
        }

        double[][] add(double[][] other) {
            double[][] result = new double[a.length][a[0].length];
            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < a[0].length; j++) {
                    result[i][j] = a[i][j] + other[i][j];
                }
            }
            return result;
        }

        double[][] subtract(double[][] other) {
            double[][] result = new double[a.length][a[0].length];
            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < a[0].length; j++) {
                    result[i][j] = a[i][j] - other[i][j];
                }
            }
            return result;
        }
    }

    static class NeuralNetwork {
        double[][] weights;
        double[] biases;

        NeuralNetwork(double[][] weights, double[] biases) {
            this.weights = weights;
            this.biases = biases;
        }

        double[] forward_pass(double[][] input_data) {
            MatrixOperations operations = new MatrixOperations(input_data, weights);
            double[][] weighted_sum = operations.multiply();
            double[][] biased_sum = operations.add(new double[][]{biases});
            return activation_function(biased_sum);
        }

        double[] activation_function(double[][] x) {
            double[] result = new double[x.length];
            for (int i = 0; i < x.length; i++) {
                result[i] = Math.max(0, x[i][0]);
            }
            return result;
        }
    }

    public static void main(String[] args) {
        double[][] input_data = {{1, 2}, {3, 4}};
        double[][] weights = {{0.1, 0.2}, {0.3, 0.4}};
        double[] biases = {0.5, 0.6};
        NeuralNetwork nn = new NeuralNetwork(weights, biases);
        double[] output = nn.forward_pass(input_data);
        System.out.println(Arrays.toString(output));
    }
}