import java.util.Random;

public class sample_0661 {

    public static void main(String[] args) {
        int s = 100;
        int k = 100;
        double r = 0.05;
        int t = 1;
        double v = 0.2;
        int n = 1000;
        System.out.println(monteCarlo(n, s, r, t, v));
    }

    public static double monteCarlo(int n, int s, double r, int t, double v) {
        Random random = new Random();

        return simulate(0, s, n, random, r, v) / n;
    }

    private static double simulate(int i, int p, int n, Random random, double r, double v) {
        if (i == n) {
            return Math.max(p - s, 0);
        }
        return simulate(i + 1, (int) (p * (1 + random.nextGaussian() * v + r)), n, random, r, v);
    }
}