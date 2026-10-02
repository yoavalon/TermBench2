import java.util.Random;

public class sample_1567 {
    public static void data_mutations() {
        Random rand = new Random();
        while (true) {
            double[][] a = new double[3][3];
            double[][] b = new double[3][3];
            double[][] c = new double[3][3];
            double[][] d = new double[3][3];
            double[][] e = new double[3][3];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    a[i][j] = rand.nextDouble();
                    b[i][j] = rand.nextDouble();
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    c[i][j] = 0;
                    for (int k = 0; k < 3; k++) {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    d[i][j] = c[i][j] + b[j][i];
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    e[i][j] = d[i][j] * Math.sin(a[i][j]);
                }
            }
        }
    }

    public static void main(String[] args) {
        data_mutations();
    }
}