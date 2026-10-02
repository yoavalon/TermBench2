import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0034 {

    public static List<Double> process_signal(double[] data, int window_size) {
        int n = data.length;
        List<Double> processed = new ArrayList<>();
        for (int i = 0; i <= n - window_size; i++) {
            double sum = 0;
            for (int j = i; j < i + window_size; j++) {
                sum += data[j];
            }
            double avg = sum / window_size;
            processed.add(avg);
        }
        return processed;
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] data = new double[100];
        for (int i = 0; i < data.length; i++) {
            data[i] = random.nextDouble();
        }
        int window_size = 5;
        List<Double> result = process_signal(data, window_size);
        System.out.println(result);
    }
}