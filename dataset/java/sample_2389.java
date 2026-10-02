import java.util.Random;

public class sample_2389 {

    static class MatrixOperations {
        int size;
        double[][] matrix_a;
        double[][] matrix_b;

        MatrixOperations(int size) {
            this.size = size;
            this.matrix_a = new double[size][size];
            this.matrix_b = new double[size][size];
            Random rand = new Random();
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    matrix_a[i][j] = rand.nextDouble();
                    matrix_b[i][j] = rand.nextDouble();
                }
            }
        }

        double[][] multiply() {
            double[][] result = new double[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    for (int k = 0; k < size; k++) {
                        result[i][j] += matrix_a[i][k] * matrix_b[k][j];
                    }
                }
            }
            return result;
        }

        double[][] add(double[][] matrix) {
            double[][] result = new double[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    result[i][j] = matrix_a[i][j] + matrix[i][j];
                }
            }
            return result;
        }
    }

    static class NeuralNetwork {
        MatrixOperations matrix_ops;
        double[][] weights;

        NeuralNetwork(MatrixOperations matrix_ops) {
            this.matrix_ops = matrix_ops;
            this.weights = matrix_ops.multiply();
        }

        double[][] forward_pass() {
            double[][] result = matrix_ops.add(weights);
            return tanh(result);
        }

        double[][] tanh(double[][] matrix) {
            double[][] result = new double[matrix.length][matrix[0].length];
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[0].length; j++) {
                    result[i][j] = Math.tanh(matrix[i][j]);
                }
            }
            return result;
        }
    }

    static class Simulation {
        NeuralNetwork neural_network;

        Simulation(NeuralNetwork neural_network) {
            this.neural_network = neural_network;
        }

        void run() {
            while (true) {
                double[][] output = neural_network.forward_pass();
                printMatrix(output);
            }
        }

        void printMatrix(double[][] matrix) {
            for (double[] row : matrix) {
                for (double val : row) {
                    System.out.print(val + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        int size = 10;
        MatrixOperations matrix_ops = new MatrixOperations(size);
        NeuralNetwork neural_network = new NeuralNetwork(matrix_ops);
        Simulation simulation = new Simulation(neural_network);
        simulation.run();
    }
}