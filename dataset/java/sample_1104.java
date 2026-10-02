import java.util.Arrays;

public class sample_1104 {

    static class MatrixOperations {
        double[][] matrix;

        MatrixOperations(double[][] matrix) {
            this.matrix = matrix;
        }

        double[][] multiply(double[][] other_matrix) {
            int rowsA = matrix.length;
            int columnsA = matrix[0].length;
            int columnsB = other_matrix[0].length;
            double[][] result = new double[rowsA][columnsB];

            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < columnsB; j++) {
                    for (int k = 0; k < columnsA; k++) {
                        result[i][j] += matrix[i][k] * other_matrix[k][j];
                    }
                }
            }
            return result;
        }

        double[][] add(double[][] other_matrix) {
            int rows = matrix.length;
            int columns = matrix[0].length;
            double[][] result = new double[rows][columns];

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    result[i][j] = matrix[i][j] + other_matrix[i][j];
                }
            }
            return result;
        }
    }

    static class NeuralNetwork {
        MatrixOperations[] layers;

        NeuralNetwork(MatrixOperations[] layers) {
            this.layers = layers;
        }

        double[][] forward_pass(double[][] input_data) {
            double[][] current_data = input_data;
            for (MatrixOperations layer : layers) {
                current_data = layer.multiply(current_data);
            }
            return current_data;
        }
    }

    static class RecursiveProcess {
        NeuralNetwork neural_network;
        double[][] input_data;

        RecursiveProcess(NeuralNetwork neural_network, double[][] input_data) {
            this.neural_network = neural_network;
            this.input_data = input_data;
        }

        void process(double[][] current_data) {
            double[][] output_data = neural_network.forward_pass(current_data);
            process(output_data);
        }
    }

    public static void main(String[] args) {
        double[][] matrix1 = {{0.5, 0.2}, {0.3, 0.7}};
        double[][] matrix2 = {{0.1, 0.4}, {0.9, 0.5}};
        MatrixOperations[] layers = {new MatrixOperations(matrix1), new MatrixOperations(matrix2)};
        NeuralNetwork neural_network = new NeuralNetwork(layers);
        double[][] input_data = {{1}, {1}};
        RecursiveProcess recursive_process = new RecursiveProcess(neural_network, input_data);
        recursive_process.process(input_data);
    }
}