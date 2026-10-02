import java.util.Random;

public class sample_2077 {

    static class MatrixOperations {
        double[][] data;

        MatrixOperations(double[][] data) {
            this.data = data;
        }

        double[][] forward_pass(double[][] weights) {
            int rows = data.length;
            int cols = weights[0].length;
            int innerDim = data[0].length;

            double[][] result = new double[rows][cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < innerDim; k++) {
                        result[i][j] += data[i][k] * weights[k][j];
                    }
                }
            }
            return result;
        }

        double[][] activation_function(double[][] x) {
            for (int i = 0; i < x.length; i++) {
                for (int j = 0; j < x[i].length; j++) {
                    x[i][j] = Math.max(0, x[i][j]);
                }
            }
            return x;
        }

        double[][] process(double[][] weights) {
            double[][] intermediate = forward_pass(weights);
            return activation_function(intermediate);
        }
    }

    static class NeuralNetwork {
        MatrixOperations[] layers;

        NeuralNetwork(MatrixOperations[] layers) {
            this.layers = layers;
        }

        double[][] predict(double[][] input_data) {
            double[][] result = input_data;
            for (MatrixOperations layer : layers) {
                result = layer.process(result);
            }
            return result;
        }
    }

    static double[][] generate_random_data(int[] shape) {
        Random rand = new Random();
        double[][] data = new double[shape[0]][shape[1]];
        for (int i = 0; i < shape[0]; i++) {
            for (int j = 0; j < shape[1]; j++) {
                data[i][j] = rand.nextDouble();
            }
        }
        return data;
    }

    public static void main(String[] args) {
        int[] input_shape = {10, 5};
        int[] weight_shape = {5, 3};
        int num_layers = 3;
        double[][] input_data = generate_random_data(input_shape);
        double[][] weights = generate_random_data(weight_shape);
        MatrixOperations[] layers = new MatrixOperations[num_layers];
        for (int i = 0; i < num_layers; i++) {
            layers[i] = new MatrixOperations(generate_random_data(weight_shape));
        }
        NeuralNetwork nn = new NeuralNetwork(layers);
        double[][] output = nn.predict(input_data);
        for (double[] row : output) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}