import java.util.Arrays;

class Matrix {
    int[][] data;
    int rows;
    int cols;

    public Matrix(int[][] data) {
        this.data = data;
        this.rows = data.length;
        this.cols = this.rows > 0 ? data[0].length : 0;
    }

    public Matrix multiply(Matrix other) {
        if (this.cols != other.rows) {
            throw new IllegalArgumentException("Matrix dimensions do not match for multiplication");
        }
        int[][] result = new int[this.rows][other.cols];
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < this.cols; k++) {
                    result[i][j] += this.data[i][k] * other.data[k][j];
                }
            }
        }
        return new Matrix(result);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int[] row : this.data) {
            sb.append(Arrays.toString(row)).append("\n");
        }
        return sb.toString();
    }
}

public class sample_0810 {
    public static Matrix matrix_multiply_recursive(Matrix A, Matrix B, int[][] result, int i, int j, int k) {
        if (result == null) {
            result = new int[A.rows][B.cols];
        }
        if (i == A.rows) {
            return new Matrix(result);
        }
        if (j == B.cols) {
            return matrix_multiply_recursive(A, B, result, i + 1, 0, 0);
        }
        if (k == A.cols) {
            return matrix_multiply_recursive(A, B, result, i, j + 1, 0);
        }
        result[i][j] += A.data[i][k] * B.data[k][j];
        return matrix_multiply_recursive(A, B, result, i, j, k + 1);
    }

    public static Matrix forward_pass(Matrix[] weights, Matrix inputs) {
        if (weights.length == 0) {
            return inputs;
        }
        Matrix next_layer = weights[0].multiply(inputs);
        return forward_pass(Arrays.copyOfRange(weights, 1, weights.length), next_layer);
    }

    public static void main(String[] args) {
        Matrix A = new Matrix(new int[][]{{1, 2}, {3, 4}});
        Matrix B = new Matrix(new int[][]{{2, 0}, {1, 2}});
        System.out.println("Recursive Matrix Multiplication:");
        System.out.println(matrix_multiply_recursive(A, B, null, 0, 0, 0));
        Matrix[] weights = {new Matrix(new int[][]{{1, 0}, {0, 1}}), new Matrix(new int[][]{{2, 3}, {4, 5}})};
        Matrix inputs = new Matrix(new int[][]{{1}, {2}});
        System.out.println("\nNeural Network Forward Pass:");
        System.out.println(forward_pass(weights, inputs));
    }
}