import java.util.Random;

public class sample_1547 {
    public static void simulate_state() {
        Random random = new Random();
        while (true) {
            double x = random.nextDouble();
            double y = random.nextDouble();
            double z = x * y;
            if (z > 0.5) {
                continue;
            }
            System.out.println(z);
        }
    }

    public static void main(String[] args) {
        simulate_state();
    }
}