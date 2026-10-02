import java.util.Random;

public class sample_2187 {
    public static void simulate_decay() {
        Random random = new Random();
        double val = 1.0;
        while (true) {
            double decay_factor = random.nextDouble() * 0.09 + 0.9;
            val *= decay_factor;
            System.out.println(val);
        }
    }

    public static void main(String[] args) {
        simulate_decay();
    }
}