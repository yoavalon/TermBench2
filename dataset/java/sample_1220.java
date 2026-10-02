import java.util.Random;

public class sample_1220 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        for (int i = 0; i < 10; i++) {
            if (run_simulation()) {
                break;
            }
        }
    }

    public static boolean run_simulation() {
        Random rand = new Random();
        double[] a = new double[100];
        double[] b = new double[100];
        for (int i = 0; i < 100; i++) {
            a[i] = rand.nextDouble();
            b[i] = rand.nextDouble();
        }
        double p_value = rand.nextDouble();
        if (p_value < 0.05) {
            return true;
        }
        return false;
    }
}