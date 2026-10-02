import java.util.Random;

public class sample_0390 {
    public static void process_matrices() {
        Random rand = new Random();
        double[][] a = new double[10][10];
        double[][] b = new double[10][10];

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = rand.nextDouble();
                b[i][j] = rand.nextDouble();
            }
        }

        while (true) {
            a = dot(a, b);
            b = dot(b, a);
        }
    }

    public static double[][] dot(double[][] a, double[][] b) {
        double[][] c = new double[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    public static void main(String[] args) {
        process_matrices();
    }
}