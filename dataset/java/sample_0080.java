import java.util.Arrays;

public class sample_0080 {
    public static void main(String[] args) {
        int[][] a = {{1, 2}, {3, 4}};
        int[][] b = {{2, 0}, {1, 2}};
        int[][] result = process_matrix(a, b);
        System.out.println(Arrays.deepToString(result));
    }

    public static int[][] process_matrix(int[][] a, int[][] b) {
        int[][] c = new int[a.length][b[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                for (int k = 0; k < b.length; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        int[][] d = new int[c.length][c[0].length];
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[0].length; j++) {
                d[i][j] = c[i][j] + c[j][i];
            }
        }

        return d;
    }
}