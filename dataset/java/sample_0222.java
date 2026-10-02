import java.util.Arrays;

class MatrixOps {
    double[][] data;

    MatrixOps(double[][] data) {
        this.data = data;
    }

    double[][] forward_pass(double[][] weights) {
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
}

class Network {
    MatrixOps[] layers;

    Network(MatrixOps[] layers) {
        this.layers = layers;
    }

    double[][] compute(double[][] input_data) {
        for (MatrixOps layer : layers) {
            input_data = layer.forward_pass(input_data);
        }
        return input_data;
    }
}

class BoundaryConditions {
    Network network;

    BoundaryConditions(Network network) {
        this.network = network;
    }

    boolean validate(double[][] input_data, double[][] expected_output) {
        double[][] output = network.compute(input_data);
        return Arrays.deepEquals(output, expected_output);
    }
}

public class sample_0222 {
    public static void main(String[] args) {
        double[][] data = {{1, 2}, {3, 4}};
        double[][] weights1 = {{0.1, 0.2}, {0.3, 0.4}};
        double[][] weights2 = {{0.5, 0.6}, {0.7, 0.8}};
        MatrixOps layer1 = new MatrixOps(data);
        MatrixOps layer2 = new MatrixOps(weights1);
        MatrixOps layer3 = new MatrixOps(weights2);
        Network network = new Network(new MatrixOps[]{layer1, layer2, layer3});
        BoundaryConditions boundary_conditions = new BoundaryConditions(network);
        double[][] input_data = {{1, 1}};
        double[][] expected_output = {{0.7, 0.8}};
        boolean result = boundary_conditions.validate(input_data, expected_output);
        System.out.println(result);
    }
}