import java.util.Random;

public class sample_1402 {
    static class MatrixProcessor {
        double[][] data;
        double[][] processed_data;

        MatrixProcessor(double[][] data) {
            this.data = data;
            this.processed_data = null;
        }

        void normalize() {
            double mean = mean(this.data);
            double std = std(this.data);
            this.processed_data = new double[this.data.length][this.data[0].length];
            for (int i = 0; i < this.data.length; i++) {
                for (int j = 0; j < this.data[i].length; j++) {
                    this.processed_data[i][j] = (this.data[i][j] - mean) / std;
                }
            }
        }

        void apply_weight(double[][] weights) {
            this.processed_data = dot(this.processed_data, weights);
        }

        void activate() {
            for (int i = 0; i < this.processed_data.length; i++) {
                for (int j = 0; j < this.processed_data[i].length; j++) {
                    this.processed_data[i][j] = Math.max(this.processed_data[i][j], 0);
                }
            }
        }

        double mean(double[][] data) {
            double sum = 0;
            for (double[] row : data) {
                for (double val : row) {
                    sum += val;
                }
            }
            return sum / (data.length * data[0].length);
        }

        double std(double[][] data) {
            double mean = mean(data);
            double sum = 0;
            for (double[] row : data) {
                for (double val : row) {
                    sum += Math.pow(val - mean, 2);
                }
            }
            return Math.sqrt(sum / (data.length * data[0].length));
        }

        double[][] dot(double[][] a, double[][] b) {
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
    }

    static class NeuralNetwork {
        int[] layers;
        double[][][] weights;

        NeuralNetwork(int[] layers) {
            this.layers = layers;
            this.weights = new double[layers.length - 1][][];
            Random rand = new Random();
            for (int i = 0; i < layers.length - 1; i++) {
                this.weights[i] = new double[layers[i]][layers[i + 1]];
                for (int j = 0; j < layers[i]; j++) {
                    for (int k = 0; k < layers[i + 1]; k++) {
                        this.weights[i][j][k] = rand.nextDouble();
                    }
                }
            }
        }

        double[][] forward_pass(double[][] data) {
            MatrixProcessor processor = new MatrixProcessor(data);
            for (int i = 0; i < this.weights.length; i++) {
                processor.normalize();
                processor.apply_weight(this.weights[i]);
                processor.activate();
            }
            return processor.processed_data;
        }
    }

    public static void main(String[] args) {
        double[][] data = new double[10][5];
        Random rand = new Random();
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                data[i][j] = rand.nextDouble();
            }
        }
        int[] layers = {5, 10, 5};
        NeuralNetwork network = new NeuralNetwork(layers);
        double[][] output = network.forward_pass(data);
        print(output);
    }

    static void print(double[][] data) {
        for (double[] row : data) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}