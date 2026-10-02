import java.util.Arrays;
import java.util.Random;

public class sample_1323 {
    public static double[] processSignal(double[] signal) {
        double[] filteredSignal = new double[signal.length];
        for (int i = 0; i < signal.length; i++) {
            double sum = 0;
            if (i == 0) {
                sum += 0.25 * signal[i];
                sum += 0.5 * signal[i + 1];
                sum += 0.25 * signal[i + 2];
            } else if (i == signal.length - 1) {
                sum += 0.25 * signal[i];
                sum += 0.5 * signal[i - 1];
                sum += 0.25 * signal[i - 2];
            } else {
                sum += 0.25 * signal[i - 1];
                sum += 0.5 * signal[i];
                sum += 0.25 * signal[i + 1];
            }
            filteredSignal[i] = sum;
        }
        return filteredSignal;
    }

    public static boolean[] analyzeData(double[] data) {
        double[] processedData = processSignal(data);
        double mean = Arrays.stream(processedData).average().orElse(0.0);
        double std = Math.sqrt(Arrays.stream(processedData).map(x -> (x - mean) * (x - mean)).average().orElse(0.0));
        double threshold = mean + 2 * std;
        boolean[] anomalies = new boolean[processedData.length];
        for (int i = 0; i < processedData.length; i++) {
            anomalies[i] = processedData[i] > threshold;
        }
        return anomalies;
    }

    public static void main(String[] args) {
        double[] data = new double[100];
        Random random = new Random();
        for (int i = 0; i < data.length; i++) {
            data[i] = random.nextDouble();
        }
        boolean[] result = analyzeData(data);
        System.out.println(Arrays.toString(result));
    }
}