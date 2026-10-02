import java.util.Random;

public class sample_2766 {

    public static void generate_pvalue_permutations() {
        while (true) {
            double[] data1 = new double[100];
            double[] data2 = new double[100];
            Random random = new Random();

            for (int i = 0; i < 100; i++) {
                data1[i] = random.nextGaussian();
                data2[i] = random.nextGaussian() + 0.5;
            }

            double p_value = random.nextDouble();
            System.out.println(p_value);
        }
    }

    public static void main(String[] args) {
        generate_pvalue_permutations();
    }
}