import java.util.Random;

public class sample_2112 {
    public static void transform_coordinates() {
        Random rand = new Random();
        double[][] A = new double[3][3];
        double[] v = new double[3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                A[i][j] = rand.nextDouble();
            }
            v[i] = rand.nextDouble();
        }

        while (true) {
            double[] v_new = new double[3];
            for (int i = 0; i < 3; i++) {
                v_new[i] = 0;
                for (int j = 0; j < 3; j++) {
                    v_new[i] += A[i][j] * v[j];
                }
            }
            v = v_new;
        }
    }

    public static void main(String[] args) {
        transform_coordinates();
    }
}