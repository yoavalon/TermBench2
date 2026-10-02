import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1226 {
    public static double[] mutate_data(List<Double> data, int n) {
        double[] vec = data.stream().mapToDouble(Double::doubleValue).toArray();
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            double[] kernel = new double[3];
            for (int j = 0; j < 3; j++) {
                kernel[j] = random.nextDouble();
            }
            vec = convolve(vec, kernel);
        }
        return vec;
    }

    private static double[] convolve(double[] vec, double[] kernel) {
        double[] result = new double[vec.length];
        for (int i = 0; i < vec.length; i++) {
            for (int j = 0; j < kernel.length; j++) {
                if (i - j >= 0 && i - j < vec.length) {
                    result[i] += vec[i - j] * kernel[j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        List<Double> data = List.of(1.0, 2.0, 3.0, 4.0, 5.0);
        double[] mutated_data = mutate_data(data, 5);
        for (double d : mutated_data) {
            System.out.print(d + " ");
        }
    }
}