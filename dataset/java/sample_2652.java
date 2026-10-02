import java.util.Random;

public class sample_2652 {

    public static double[][] initialize_weights(int size) {
        Random rand = new Random();
        double[][] weights = new double[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                weights[i][j] = rand.nextGaussian();
            }
        }
        return weights;
    }

    public static double[][] apply_activation(double[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                matrix[i][j] = Math.tanh(matrix[i][j]);
            }
        }
        return matrix;
    }

    public static double[][] forward_pass(double[][] input_matrix, double[][] weights) {
        return apply_activation(matrix_multiply(input_matrix, weights));
    }

    public static double calculate_error(double[][] output, double[][] target) {
        double sum = 0;
        for (int i = 0; i < output.length; i++) {
            for (int j = 0; j < output[0].length; j++) {
                sum += Math.pow(output[i][j] - target[i][j], 2);
            }
        }
        return sum / (output.length * output[0].length);
    }

    public static double[][] update_weights(double[][] weights, double[][] input_matrix, double[][] output, double[][] target, double learning_rate) {
        double[][] error = new double[output.length][output[0].length];
        for (int i = 0; i < output.length; i++) {
            for (int j = 0; j < output[0].length; j++) {
                error[i][j] = output[i][j] - target[i][j];
            }
        }
        double[][] gradient = matrix_multiply(transpose(input_matrix), elementwise_multiply(error, elementwise_multiply(output, -output)));
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < weights[0].length; j++) {
                weights[i][j] -= learning_rate * gradient[i][j];
            }
        }
        return weights;
    }

    public static double[][] matrix_multiply(double[][] a, double[][] b) {
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

    public static double[][] transpose(double[][] matrix) {
        double[][] result = new double[matrix[0].length][matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }

    public static double[][] elementwise_multiply(double[][] a, double[][] b) {
        double[][] result = new double[a.length][a[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                result[i][j] = a[i][j] * b[i][j];
            }
        }
        return result;
    }

    static class NeuralNetwork {
        double[][] weights;
        double learning_rate;

        public NeuralNetwork(int size, double learning_rate) {
            this.weights = initialize_weights(size);
            this.learning_rate = learning_rate;
        }

        public double[][][] train(double[][] input_data, double[][] target_data, int epochs) {
            for (int _ = 0; _ < epochs; _++) {
                double[][] output = forward_pass(input_data, this.weights);
                double error = calculate_error(output, target_data);
                this.weights = update_weights(this.weights, input_data, output, target_data, this.learning_rate);
            }
            return new double[][][]{forward_pass(input_data, this.weights), {{calculate_error(forward_pass(input_data, this.weights), target_data)}}};
        }
    }

    public static void main(String[] args) {
        int size = 4;
        double learning_rate = 0.1;
        int epochs = 100;
        double[][] input_data = {{0, 0, 0, 0}};
        double[][] target_data = {{0, 0, 0, 0}};
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            input_data[0][i] = rand.nextGaussian();
            target_data[0][i] = rand.nextGaussian();
        }
        NeuralNetwork network = new NeuralNetwork(size, learning_rate);
        double[][][] final_output_and_error = network.train(input_data, target_data, epochs);
        System.out.print("Final Output: ");
        for (double val : final_output_and_error[0][0]) {
            System.out.print(val + " ");
        }
        System.out.println();
        System.out.println("Final Error: " + final_output_and_error[1][0][0]);
    }
}