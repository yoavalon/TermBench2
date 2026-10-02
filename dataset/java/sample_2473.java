import java.util.Arrays;

public class sample_2473 {
    public static void main(String[] args) {
        compute_sequence(5);
    }

    public static void compute_sequence(int n) {
        int[][] a = {{1, 2}, {3, 4}};
        int[][] b = {{2, 0}, {1, 2}};
        int[] x = {1, 1};
        for (int i = 0; i < n; i++) {
            int[] temp = new int[2];
            temp[0] = a[0][0] * x[0] + a[0][1] * x[1] + b[0][0] * x[0] + b[0][1] * x[1];
            temp[1] = a[1][0] * x[0] + a[1][1] * x[1] + b[1][0] * x[0] + b[1][1] * x[1];
            x = temp;
        }
        System.out.println(Arrays.toString(x));
    }
}