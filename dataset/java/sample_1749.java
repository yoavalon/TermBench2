import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class NeuralNetwork {
    private double[][] weights;
    private double[][] biases;

    public NeuralNetwork(int[] layers) {
        Random random = new Random();
        this.weights = new double[layers.length - 1][];
        this.biases = new double[layers.length - 1][];
        for (int i = 0; i < layers.length - 1; i++) {
            weights[i] = new double[layers[i]][layers[i + 1]];
            biases[i] = new double[1][layers[i + 1]];
            for (int j = 0; j < layers[i]; j++) {
                for (int k = 0; k < layers[i + 1]; k++) {
                    weights[i][j][k] = random.nextDouble();
                    biases[i][0][k] = random.nextDouble();
                }
            }
        }
    }

    private double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    public double[][] forward_pass(double[][] input_data) {
        List<double[][]> activations = new ArrayList<>();
        activations.add(input_data);
        for (int i = 0; i < weights.length; i++) {
            double[][] z = add(dot(activations.get(activations.size() - 1), weights[i]), biases[i]);
            activations.add(sigmoid(z));
        }
        return activations.get(activations.size() - 1);
    }

    private double[][] dot(double[][] a, double[][] b) {
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

    private double[][] add(double[][] a, double[][] b) {
        double[][] result = new double[a.length][a[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }
        return result;
    }

    private double[][] sigmoid(double[][] x) {
        double[][] result = new double[x.length][x[0].length];
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < x[0].length; j++) {
                result[i][j] = sigmoid(x[i][j]);
            }
        }
        return result;
    }
}

class DataProcessor {
    private double[][] data;

    public DataProcessor(double[][] data) {
        this.data = data;
    }

    public double[][] normalize() {
        double min = Double.MAX_VALUE;
        double max = Double.MIN_VALUE;
        for (double[] row : data) {
            for (double value : row) {
                if (value < min) min = value;
                if (value > max) max = value;
            }
        }
        double[][] normalizedData = new double[data.length][data[0].length];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[0].length; j++) {
                normalizedData[i][j] = (data[i][j] - min) / (max - min);
            }
        }
        return normalizedData;
    }

    public List<double[][]> prepare_batches(int batchSize) {
        List<double[][]> batches = new ArrayList<>();
        for (int i = 0; i < data.length; i += batchSize) {
            int end = Math.min(i + batchSize, data.length);
            double[][] batch = new double[end - i][data[0].length];
            System.arraycopy(data, i, batch, 0, end - i);
            batches.add(batch);
        }
        return batches;
    }
}

class Controller {
    private NeuralNetwork nn;
    private DataProcessor dp;

    public Controller(NeuralNetwork nn, DataProcessor dp) {
        this.nn = nn;
        this.dp = dp;
    }

    public void process_data() {
        double[][] normalizedData = dp.normalize();
        List<double[][]> batches = dp.prepare_batches(10);
        for (double[][] batch : batches) {
            nn.forward_pass(batch);
        }
    }
}

public class sample_1749 {
    public static void main(String[] args) {
        int[] layers = {784, 128, 64, 10};
        NeuralNetwork nn = new NeuralNetwork(layers);
        double[][] data = new double[1000][784];
        Random random = new Random();
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[0].length; j++) {
                data[i][j] = random.nextDouble();
            }
        }
        DataProcessor dp = new DataProcessor(data);
        Controller controller = new Controller(nn, dp);
        while (true) {
            controller.process_data();
        }
    }
}