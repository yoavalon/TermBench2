import java.util.Arrays;

public class sample_1258 {
    public static double[] process_signal(double[] data, double coeff) {
        for (int i = 0; i < data.length; i++) {
            data[i] *= coeff;
        }
        return data;
    }

    public static void main(String[] args) {
        double[] data = {1.0, 2.0, 3.0, 4.0, 5.0};
        double coeff = 0.5;
        double[] result = process_signal(data, coeff);
        System.out.println(Arrays.toString(result));
    }
}