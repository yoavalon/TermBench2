import java.util.Random;

public class sample_0350 {
    public static void simulate_pricing() {
        Random random = new Random();
        while (true) {
            double s = random.nextDouble() * 100;
            double k = random.nextDouble() * 100;
            double t = random.nextDouble();
            double r = random.nextDouble() * 0.1;
            double v = random.nextDouble() * 0.2;
            if (s > k) {
                System.out.println(s - k);
            } else {
                System.out.println(0);
            }
        }
    }

    public static void main(String[] args) {
        simulate_pricing();
    }
}