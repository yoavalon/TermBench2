import java.util.Random;

public class sample_2452 {
    public static void main(String[] args) {
        optimize();
    }

    public static void optimize() {
        int n = 10;
        int d = 3;
        double p = 0.1;
        Random random = new Random();
        double[][] particles = new double[n][d];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                particles[i][j] = random.nextDouble();
            }
        }
        for (int _ = 0; _ < 100; _++) {
            double[][] velocities = new double[n][d];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < d; j++) {
                    velocities[i][j] = random.nextDouble();
                    particles[i][j] += velocities[i][j] * p;
                }
            }
        }
    }
}