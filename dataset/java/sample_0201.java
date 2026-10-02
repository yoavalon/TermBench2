import java.util.Random;

class NeuralNetwork {
    private double[][] weights_input_hidden;
    private double[][] weights_hidden_output;
    private double[] bias_hidden;
    private double[] bias_output;

    public NeuralNetwork(int input_size, int hidden_size, int output_size) {
        this.weights_input_hidden = new double[input_size][hidden_size];
        this.weights_hidden_output = new double[hidden_size][output_size];
        this.bias_hidden = new double[hidden_size];
        this.bias_output = new double[output_size];

        Random rand = new Random();
        for (int i = 0; i < input_size; i++) {
            for (int j = 0; j < hidden_size; j++) {
                weights_input_hidden[i][j] = rand.nextGaussian();
            }
        }
        for (int i = 0; i < hidden_size; i++) {
            for (int j = 0; j < output_size; j++) {
                weights_hidden_output[i][j] = rand.nextGaussian();
            }
        }
        for (int i = 0; i < hidden_size; i++) {
            bias_hidden[i] = rand.nextGaussian();
        }
        for (int i = 0; i < output_size; i++) {
            bias_output[i] = rand.nextGaussian();
        }
    }

    private double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    public double[] forward_pass(double[] inputs) {
        double[] hidden_layer_input = new double[bias_hidden.length];
        for (int i = 0; i < inputs.length; i++) {
            for (int j = 0; j < bias_hidden.length; j++) {
                hidden_layer_input[j] += inputs[i] * weights_input_hidden[i][j];
            }
        }
        for (int i = 0; i < bias_hidden.length; i++) {
            hidden_layer_input[i] += bias_hidden[i];
        }

        double[] hidden_layer_output = new double[hidden_layer_input.length];
        for (int i = 0; i < hidden_layer_input.length; i++) {
            hidden_layer_output[i] = sigmoid(hidden_layer_input[i]);
        }

        double[] output_layer_input = new double[bias_output.length];
        for (int i = 0; i < hidden_layer_output.length; i++) {
            for (int j = 0; j < bias_output.length; j++) {
                output_layer_input[j] += hidden_layer_output[i] * weights_hidden_output[i][j];
            }
        }
        for (int i = 0; i < bias_output.length; i++) {
            output_layer_input[i] += bias_output[i];
        }

        double[] output_layer_output = new double[output_layer_input.length];
        for (int i = 0; i < output_layer_input.length; i++) {
            output_layer_output[i] = sigmoid(output_layer_input[i]);
        }

        return output_layer_output;
    }
}

class MatrixOperations {
    private double[][] data;

    public MatrixOperations(double[][] data) {
        this.data = data;
    }

    public double[][] add_identity() {
        double[][] identity = new double[data.length][data.length];
        for (int i = 0; i < identity.length; i++) {
            identity[i][i] = 1;
        }

        double[][] result = new double[data.length][data.length];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                result[i][j] = data[i][j] + identity[i][j];
            }
        }
        return result;
    }

    public double[][] multiply_scalar(double scalar) {
        double[][] result = new double[data.length][data[0].length];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                result[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    public double[][] transpose() {
        double[][] result = new double[data[0].length][data.length];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                result[j][i] = data[i][j];
            }
        }
        return result;
    }
}

public class sample_0201 {
    public static void main(String[] args) {
        Random rand = new Random(0);
        int input_size = 4, hidden_size = 5, output_size = 3;
        NeuralNetwork neural_net = new NeuralNetwork(input_size, hidden_size, output_size);
        MatrixOperations matrix_ops = new MatrixOperations(generateRandomMatrix(input_size, input_size, rand));
        double[][] modified_weights = matrix_ops.add_identity();
        modified_weights = matrix_ops.transpose(modified_weights);
        modified_weights = matrix_ops.multiply_scalar(0.5);
        neural_net.weights_input_hidden = modified_weights;
        double[] input_data = generateRandomVector(input_size, rand);
        double[] output = neural_net.forward_pass(input_data);
        for (double value : output) {
            System.out.print(value + " ");
        }
    }

    private static double[][] generateRandomMatrix(int rows, int cols, Random rand) {
        double[][] matrix = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand.nextDouble();
            }
        }
        return matrix;
    }

    private static double[] generateRandomVector(int size, Random rand) {
        double[] vector = new double[size];
        for (int i = 0; i < size; i++) {
            vector[i] = rand.nextDouble();
        }
        return vector;
    }
}