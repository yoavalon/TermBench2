public class sample_0767 {
    public static double[][] matrix_multiply(double[][] A, double[][] B) {
        if (A[0].length != B.length) {
            throw new IllegalArgumentException();
        }
        double[][] result = new double[A.length][B[0].length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B[0].length; j++) {
                for (int k = 0; k < B.length; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    }

    public static double[][] forward_pass(double[][][] weights, double[][] inputs) {
        for (double[][] weight : weights) {
            inputs = matrix_multiply(weight, inputs);
        }
        return inputs;
    }

    public static void main(String[] args) {
        double[][][] weights = {
            {{0.5, 0.2}, {0.1, 0.8}},
            {{0.4, 0.6}, {0.7, 0.3}}
        };
        double[][] inputs = {{1}, {2}};
        double[][] output = forward_pass(weights, inputs);
        for (double[] row : output) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}