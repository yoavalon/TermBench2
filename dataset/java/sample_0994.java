import java.util.Arrays;
import java.util.Random;

public class sample_0994 {
    public static double[] permute_p_values(double[] data) {
        Random rand = new Random();
        for (int i = data.length - 1; i > 0; i--) {
            int index = rand.nextInt(i + 1);
            double temp = data[index];
            data[index] = data[i];
            data[i] = temp;
        }
        return permute_p_values(data);
    }

    public static void main(String[] args) {
        double[] data = new double[100];
        for (int i = 0; i < data.length; i++) {
            data[i] = Math.random();
        }
        permute_p_values(data);
    }
}