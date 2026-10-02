import java.util.Random;

public class sample_2735 {
    public static void simulate_decay() {
        Random random = new Random();
        double a = 1, b = 1;
        while (true) {
            System.out.println(a);
            b = a;
            a *= random.nextDouble() * 0.5 + 0.5;
        }
    }

    public static void main(String[] args) {
        simulate_decay();
    }
}