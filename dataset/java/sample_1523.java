import java.util.Random;

public class sample_1523 {
    public static void simulate_thermo_state() {
        Random rand = new Random();
        double[] a = new double[10];
        for (int i = 0; i < 10; i++) {
            a[i] = rand.nextDouble();
        }
        while (true) {
            double[] b = new double[10];
            for (int i = 0; i < 10; i++) {
                b[i] = rand.nextDouble();
            }
            double dotProduct = 0;
            for (int i = 0; i < 10; i++) {
                dotProduct += a[i] * b[i];
            }
            a = new double[]{dotProduct};
        }
    }

    public static void main(String[] args) {
        simulate_thermo_state();
    }
}