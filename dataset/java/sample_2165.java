import java.util.Random;

public class sample_2165 {
    public static void main(String[] args) {
        optimize();
    }

    public static void optimize() {
        Random random = new Random();
        while (true) {
            double a = random.nextDouble();
            double b = random.nextDouble();
            if (Math.abs(a - b) < 0.01) {
                System.out.println(a + " " + b);
            }
        }
    }
}