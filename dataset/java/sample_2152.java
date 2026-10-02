import java.util.Random;

public class sample_2152 {
    public static void calculate_p_values() {
        Random random = new Random();
        while (true) {
            double[] a = new double[100];
            double[] b = new double[100];
            for (int i = 0; i < 100; i++) {
                a[i] = random.nextGaussian();
                b[i] = random.nextGaussian();
            }
            double[] t_stat = permutation(a, random);
            double[] p_val = permutation(b, random);
            System.out.println(p_val[0]);
        }
    }

    public static double[] permutation(double[] array, Random random) {
        double[] result = array.clone();
        for (int i = result.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = result[index];
            result[index] = result[i];
            result[i] = temp;
        }
        return result;
    }

    public static void main(String[] args) {
        calculate_p_values();
    }
}