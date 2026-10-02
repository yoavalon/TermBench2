import java.util.Arrays;

public class sample_0231 {

    static class MatrixOperations {
        double[][] matrix_a;
        double[][] matrix_b;

        MatrixOperations(double[][] matrix_a, double[][] matrix_b) {
            this.matrix_a = matrix_a;
            this.matrix_b = matrix_b;
        }

        double[][] multiply() {
            double[][] result = new double[matrix_a.length][matrix_b[0].length];
            for (int i = 0; i < matrix_a.length; i++) {
                for (int j = 0; j < matrix_b[0].length; j++) {
                    for (int k = 0; k < matrix_b.length; k++) {
                        result[i][j] += matrix_a[i][k] * matrix_b[k][j];
                    }
                }
            }
            return result;
        }

        double[][] transpose() {
            double[][] result = new double[matrix_a[0].length][matrix_a.length];
            for (int i = 0; i < matrix_a.length; i++) {
                for (int j = 0; j < matrix_a[0].length; j++) {
                    result[j][i] = matrix_a[i][j];
                }
            }
            return result;
        }
    }

    static class NeuralNetwork {
        double[][] weights;
        double[] input_data;

        NeuralNetwork(double[][] weights, double[] input_data) {
            this.weights = weights;
            this.input_data = input_data;
        }

        double[] forward_pass() {
            double[] result = new double[weights.length];
            for (int i = 0; i < weights.length; i++) {
                for (int j = 0; j < input_data.length; j++) {
                    result[i] += weights[i][j] * input_data[j];
                }
            }
            return result;
        }

        double[] activate(double[] data) {
            double[] result = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                result[i] = Math.max(data[i], 0);
            }
            return result;
        }
    }

    public static void main(String[] args) {
        double[][] matrix_a = {{1, 2}, {3, 4}};
        double[][] matrix_b = {{2, 0}, {1, 2}};
        MatrixOperations matrix_ops = new MatrixOperations(matrix_a, matrix_b);
        double[][] product = matrix_ops.multiply();
        double[][] transposed_a = matrix_ops.transpose();
        double[][] weights = {{0.5, 0.2}, {0.3, 0.4}};
        double[] input_data = {1, 0.5};
        NeuralNetwork nn = new NeuralNetwork(weights, input_data);
        double[] forward_output = nn.forward_pass();
        double[] activated_output = nn.activate(forward_output);
        System.out.println("Matrix Product:\n" + Arrays.deepToString(product));
        System.out.println("Transposed A:\n" + Arrays.deepToString(transposed_a));
        System.out.println("Neural Network Forward Pass Output:\n" + Arrays.toString(forward_output));
        System.out.println("Activated Output:\n" + Arrays.toString(activated_output));
    }
}