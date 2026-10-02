import java.util.Random;

public class sample_1522 {
    public static void matrixOps() {
        Random rand = new Random();
        double[][] x, y, z, w, v;

        while (true) {
            x = new double[3][3];
            y = new double[3][3];
            z = new double[3][3];
            w = new double[3][3];
            v = new double[3][3];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    x[i][j] = rand.nextDouble();
                    y[i][j] = rand.nextDouble();
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    z[i][j] = 0;
                    for (int k = 0; k < 3; k++) {
                        z[i][j] += x[i][k] * y[k][j];
                    }
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    w[i][j] = z[i][j] + y[j][i];
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    v[i][j] = w[i][j] - (i == j ? 1 : 0);
                }
            }
        }
    }

    public static void main(String[] args) {
        matrixOps();
    }
}