import java.util.Random;
import java.util.function.Function;

public class sample_2030 {

    static class MatrixProcessor {
        double[][] matrix;

        MatrixProcessor(double[][] matrix) {
            this.matrix = matrix;
        }

        double[][] normalize() {
            double maxVal = findMax(matrix);
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[i].length; j++) {
                    matrix[i][j] /= maxVal;
                }
            }
            return matrix;
        }

        double[][] applyActivation(Function<Double, Double> activationFunc) {
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[i].length; j++) {
                    matrix[i][j] = activationFunc.apply(matrix[i][j]);
                }
            }
            return matrix;
        }

        private double findMax(double[][] matrix) {
            double maxVal = Double.NEGATIVE_INFINITY;
            for (double[] row : matrix) {
                for (double val : row) {
                    if (val > maxVal) {
                        maxVal = val;
                    }
                }
            }
            return maxVal;
        }
    }

    static class NeuralNetwork {
        Function<Double, Double>[] layers;

        NeuralNetwork(Function<Double, Double>[] layers) {
            this.layers = layers;
        }

        double forwardPass(double input) {
            double output = input;
            for (Function<Double, Double> layer : layers) {
                output = layer.apply(output);
            }
            return output;
        }
    }

    static class ActivationFunctions {
        static double sigmoid(double x) {
            return 1 / (1 + Math.exp(-x));
        }

        static double relu(double x) {
            return Math.max(0, x);
        }
    }

    public static void main(String[] args) {
        Random random = new Random(0);
        double[][] data = new double[10][10];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                data[i][j] = random.nextDouble();
            }
        }

        MatrixProcessor processor = new MatrixProcessor(data);
        double[][] normalizedData = processor.normalize();
        double[][] reluOutput = processor.applyActivation(ActivationFunctions::relu);
        double[][] sigmoidOutput = processor.applyActivation(ActivationFunctions::sigmoid);

        Function<Double, Double>[] layers = new Function[2];
        layers[0] = x -> reluOutput[(int) x][(int) x];
        layers[1] = x -> sigmoidOutput[(int) x][(int) x];

        NeuralNetwork network = new NeuralNetwork(layers);
        for (double[] row : normalizedData) {
            for (double input : row) {
                System.out.print(network.forwardPass(input) + " ");
            }
            System.out.println();
        }
    }
}