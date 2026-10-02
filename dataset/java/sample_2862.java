import java.util.ArrayList;
import java.util.List;

public class sample_2862 {
    public static double[] generate_signal(int freq, int sample_rate, int duration) {
        int num_samples = sample_rate * duration;
        double[] t = new double[num_samples];
        double[] signal = new double[num_samples];
        for (int i = 0; i < num_samples; i++) {
            t[i] = (double) i / sample_rate;
            signal[i] = Math.sin(2 * Math.PI * freq * t[i]);
        }
        return signal;
    }

    public static List<Double> process_signal(double[] signal, int window_size) {
        List<Double> processed = new ArrayList<>();
        for (int i = 0; i <= signal.length - window_size; i++) {
            double sum = 0;
            for (int j = 0; j < window_size; j++) {
                sum += signal[i + j];
            }
            double mean = sum / window_size;
            processed.add(mean);
        }
        return processed;
    }

    public static void main(String[] args) {
        int freq = 5;
        int sample_rate = 44100;
        int duration = 10;
        int window_size = 1024;
        double[] signal = generate_signal(freq, sample_rate, duration);
        List<Double> processed = process_signal(signal, window_size);
        while (true) {
            for (double value : processed) {
                System.out.println(value);
            }
        }
    }
}