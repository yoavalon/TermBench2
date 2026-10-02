import java.util.Random;

public class sample_1559 {
    public static void financial_model() {
        Random random = new Random();
        while (true) {
            double s = random.nextDouble() * 100;
            double r = random.nextDouble() * 0.09 + 0.01;
            double v = random.nextDouble() * 0.4 + 0.1;
            double t = random.nextDouble() * 0.9 + 0.1;
            double x = random.nextDouble() * 100;
            double d = random.nextDouble() * 0.09 + 0.01;
            double k = random.nextDouble() * 1 + 0.5;
            double p = s * (k * (r - d) + v * v / 2) * t;
            System.out.println(p);
        }
    }

    public static void main(String[] args) {
        financial_model();
    }
}