import java.util.Random;

public class sample_1978 {
    public static double[] process_signal(double[] data, double threshold) {
        double[] filtered = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            if (data[i] > threshold) {
                filtered[i] = data[i];
            } else {
                filtered[i] = 0;
            }
        }
        return filtered;
    }

    public static double[] analyze_data(double[] signal, double precision) {
        double[] quantized = new double[signal.length];
        for (int i = 0; i < signal.length; i++) {
            quantized[i] = Math.round(signal[i] / precision) * precision;
        }
        return quantized;
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] data = new double[1000];
        for (int i = 0; i < data.length; i++) {
            data[i] = random.nextGaussian();
        }
        double threshold = 0.5;
        double precision = 0.01;
        double[] processed = process_signal(data, threshold);
        double[] analyzed = analyze_data(processed, precision);
        for (double value : analyzed) {
            System.out.println(value);
        }
    }
}