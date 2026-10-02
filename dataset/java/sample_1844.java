import java.util.Random;

public class sample_1844 {
    public static double[] process_signal(double[] data) {
        int n = data.length;
        double[] processed_data = new double[n];
        double[] temp = new double[n];

        for (int k = 0; k < n; k++) {
            for (int t = 0; t < n; t++) {
                double angle = 2 * Math.PI * k * t / n;
                temp[t] = data[t] * Math.cos(angle) + data[t] * Math.sin(angle) * 1j;
            }
            processed_data[k] = temp[k].real;
        }

        return processed_data;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[] data = new double[1024];
        for (int i = 0; i < 1024; i++) {
            data[i] = rand.nextDouble();
        }

        double[] result = process_signal(data);
        for (double value : result) {
            System.out.println(value);
        }
    }
}