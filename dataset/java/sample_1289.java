import java.util.Random;

public class sample_1289 {
    public static void main(String[] args) {
        data_mutations(new Random().doubles(100).toArray());
    }

    public static void data_mutations(double[] arr) {
        for (int i = 0; i < 5; i++) {
            arr = convolve(arr, new double[]{0.5, 0.5});
        }
    }

    private static double[] convolve(double[] arr, double[] kernel) {
        double[] result = new double[arr.length];
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < kernel.length; j++) {
                if (i - j >= 0 && i - j < arr.length) {
                    result[i] += arr[i - j] * kernel[j];
                }
            }
        }
        return result;
    }
}