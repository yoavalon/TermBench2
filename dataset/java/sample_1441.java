import java.util.Arrays;

public class sample_1441 {

    static class MatrixProcessor {

        double[][] data;

        MatrixProcessor(double[][] data) {
            this.data = data;
        }

        double[][] apply_transformation(double[][] weights) {
            double[][] result = new double[data.length][weights[0].length];
            for (int i = 0; i < data.length; i++) {
                for (int j = 0; j < weights[0].length; j++) {
                    for (int k = 0; k < weights.length; k++) {
                        result[i][j] += data[i][k] * weights[k][j];
                    }
                }
            }
            return result;
        }

        double sigmoid(double x) {
            return 1 / (1 + Math.exp(-x));
        }

        double[][] forward_pass(double[][] weights) {
            double[][] transformed = apply_transformation(weights);
            double[][] activated = new double[transformed.length][transformed[0].length];
            for (int i = 0; i < transformed.length; i++) {
                for (int j = 0; j < transformed[0].length; j++) {
                    activated[i][j] = sigmoid(transformed[i][j]);
                }
            }
            return activated;
        }
    }

    static class DataMutator {

        double[][] matrix;

        DataMutator(double[][] matrix) {
            this.matrix = matrix;
        }

        double[][] mutate(double factor) {
            double[][] result = new double[matrix.length][matrix[0].length];
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[0].length; j++) {
                    result[i][j] = matrix[i][j] * factor;
                }
            }
            return result;
        }

        double[][] normalize() {
            double norm = 0;
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[0].length; j++) {
                    norm += matrix[i][j] * matrix[i][j];
                }
            }
            norm = Math.sqrt(norm);
            double[][] result = new double[matrix.length][matrix[0].length];
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[0].length; j++) {
                    result[i][j] = matrix[i][j] / norm;
                }
            }
            return result;
        }

        double[][] process(double factor) {
            double[][] mutated = mutate(factor);
            double[][] normalized = normalize();
            return normalized;
        }
    }

    static class NeuralNetwork {

        double[][] input_data;
        double[][] weights;

        NeuralNetwork(double[][] input_data, double[][] weights) {
            this.input_data = input_data;
            this.weights = weights;
        }

        double[][] execute() {
            MatrixProcessor processor = new MatrixProcessor(input_data);
            double[][] activated_output = processor.forward_pass(weights);
            return activated_output;
        }
    }

    public static void main(String[] args) {
        double[][] data = new double[10][5];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[0].length; j++) {
                data[i][j] = Math.random();
            }
        }

        double[][] weights = new double[5][3];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < weights[0].length; j++) {
                weights[i][j] = Math.random();
            }
        }

        double factor = 2.0;
        DataMutator mutator = new DataMutator(data);
        double[][] processed_data = mutator.process(factor);
        NeuralNetwork network = new NeuralNetwork(processed_data, weights);
        double[][] output = network.execute();
        System.out.println(Arrays.deepToString(output));
    }
}