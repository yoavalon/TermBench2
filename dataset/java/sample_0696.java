import java.util.Arrays;

public class sample_0696 {
    public static int[][] matrix_op(int[][] a, int[][] b, int depth) {
        if (depth == 0) {
            return a;
        }
        return dot(a, matrix_op(b, a, depth - 1));
    }

    public static int[][] dot(int[][] a, int[][] b) {
        int rowsA = a.length;
        int colsA = a[0].length;
        int colsB = b[0].length;
        int[][] result = new int[rowsA][colsB];

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[][] a = {{1, 2}, {3, 4}};
        int[][] b = {{2, 0}, {1, 2}};
        int[][] result = matrix_op(a, b, 3);
        System.out.println(Arrays.deepToString(result));
    }
}