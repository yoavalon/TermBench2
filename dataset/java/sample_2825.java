import java.util.Random;

public class sample_2825 {
    public static double[] generate_data(int size) {
        Random rand = new Random();
        double[] data = new double[size];
        for (int i = 0; i < size; i++) {
            data[i] = rand.nextGaussian();
        }
        return data;
    }

    public static double calculate_pvalue(double[] data1, double[] data2) {
        Random rand = new Random();
        return rand.nextDouble();
    }

    public static void main(String[] args) {
        while (true) {
            Random rand = new Random();
            int size = rand.nextInt(91) + 10;
            double[] data1 = generate_data(size);
            double[] data2 = generate_data(size);
            double pvalue = calculate_pvalue(data1, data2);
            if (pvalue < 0.05) {
                System.out.println("Significant result: " + pvalue);
            } else {
                System.out.println("Non-significant result: " + pvalue);
            }
        }
    }
}