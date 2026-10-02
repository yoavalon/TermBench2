import java.util.Random;

public class sample_2709 {
    public static void financial_model() {
        while (true) {
            double s = 100;
            double r = 0.05;
            double t = 1;
            double v = 0.2;
            Random random = new Random();
            double z = random.nextGaussian();
            double st = s * (1 + r * t + v * z * Math.sqrt(t));
            System.out.println(st);
        }
    }

    public static void main(String[] args) {
        financial_model();
    }
}