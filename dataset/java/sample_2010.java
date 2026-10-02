import java.util.ArrayList;
import java.util.List;

public class sample_2010 {

    static class MatrixOperations {
        float[][] a;
        float[][] b;

        MatrixOperations(float[][] a, float[][] b) {
            this.a = a;
            this.b = b;
        }

        float[][] multiply() {
            int rowsA = a.length;
            int colsA = a[0].length;
            int colsB = b[0].length;
            float[][] result = new float[rowsA][colsB];

            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsB; j++) {
                    for (int k = 0; k < colsA; k++) {
                        result[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            return result;
        }

        float[][] add() {
            int rows = a.length;
            int cols = a[0].length;
            float[][] result = new float[rows][cols];

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = a[i][j] + b[i][j];
                }
            }
            return result;
        }

        float[][] subtract() {
            int rows = a.length;
            int cols = a[0].length;
            float[][] result = new float[rows][cols];

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = a[i][j] - b[i][j];
                }
            }
            return result;
        }
    }

    static class NeuralNetwork {
        List<MatrixOperations> layers;

        NeuralNetwork(List<MatrixOperations> layers) {
            this.layers = layers;
        }

        float[][] forward_pass(float[][] input_data) {
            float[][] result = input_data;
            for (MatrixOperations layer : layers) {
                result = layer.multiply();
            }
            return result;
        }
    }

    public static void main(String[] args) {
        float[][] a = {{1.0f, 2.0f}, {3.0f, 4.0f}};
        float[][] b = {{2.0f, 0.0f}, {1.0f, 2.0f}};
        float[][] c = {{0.5f, 1.5f}, {2.5f, 3.5f}};
        MatrixOperations op1 = new MatrixOperations(a, b);
        MatrixOperations op2 = new MatrixOperations(op1.multiply(), c);
        List<MatrixOperations> layers = new ArrayList<>();
        layers.add(op1);
        layers.add(op2);
        NeuralNetwork nn = new NeuralNetwork(layers);
        float[][] input_data = {{1.0f, 1.0f}, {1.0f, 1.0f}};
        float[][] output = nn.forward_pass(input_data);
        for (float[] row : output) {
            for (float val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}