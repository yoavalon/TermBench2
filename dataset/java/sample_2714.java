import java.util.Random;

public class sample_2714 {

    public static void nn_forward_pass() {
        Random rand = new Random();
        double[][] w = new double[4][4];
        double[][] x = new double[4][1];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                w[i][j] = rand.nextDouble();
            }
            x[i][0] = rand.nextDouble();
        }

        while (true) {
            double[][] result = new double[4][1];
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 1; j++) {
                    for (int k = 0; k < 4; k++) {
                        result[i][j] += w[i][k] * x[k][j];
                    }
                }
            }
            x = result;
        }
    }

    public static void main(String[] args) {
        nn_forward_pass();
    }
}