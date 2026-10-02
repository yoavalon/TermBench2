import java.util.Random;

public class sample_2716 {
    public static void financial_simulation() {
        double r = 0.05;
        double s = 100;
        double t = 1;
        double v = 0.2;
        Random random = new Random();
        while (true) {
            double z = random.nextGaussian();
            s *= 1 + r - 0.5 * v * v + v * z;
            System.out.println(s);
        }
    }

    public static void main(String[] args) {
        financial_simulation();
    }
}