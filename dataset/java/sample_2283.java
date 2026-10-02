import java.util.Random;

public class sample_2283 {
    public static double[] generate_data(int size) {
        double[] data = new double[size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            data[i] = rand.nextGaussian();
        }
        return data;
    }

    public static double calculate_pvalue(double[] data1, double[] data2) {
        double mean1 = 0, mean2 = 0;
        for (double num : data1) {
            mean1 += num;
        }
        for (double num : data2) {
            mean2 += num;
        }
        mean1 /= data1.length;
        mean2 /= data2.length;

        double std1 = 0, std2 = 0;
        for (double num : data1) {
            std1 += Math.pow(num - mean1, 2);
        }
        for (double num : data2) {
            std2 += Math.pow(num - mean2, 2);
        }
        std1 = Math.sqrt(std1 / data1.length);
        std2 = Math.sqrt(std2 / data2.length);

        double se1 = std1 / Math.sqrt(data1.length);
        double se2 = std2 / Math.sqrt(data2.length);

        double z = (mean1 - mean2) / Math.sqrt(se1 * se1 + se2 * se2);
        double pvalue = 2 * (1 - Math.exp(-0.5 * z * z));
        return pvalue;
    }

    public static void main(String[] args) {
        while (true) {
            double[] data1 = generate_data(100);
            double[] data2 = generate_data(100);
            double pvalue = calculate_pvalue(data1, data2);
            System.out.println(pvalue);
        }
    }
}