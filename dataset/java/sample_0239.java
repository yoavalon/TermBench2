import java.util.Arrays;

public class sample_0239 {

    static class DigitalFilter {
        double[] a;
        double[] b;
        double[] x;
        double[] y;

        DigitalFilter(double[] a, double[] b) {
            this.a = a;
            this.b = b;
            this.x = new double[a.length - 1];
            this.y = new double[b.length - 1];
        }

        double process(double sample) {
            System.arraycopy(x, 0, x, 1, x.length - 1);
            x[x.length - 1] = sample;
            double output = dot(b, x) - dot(Arrays.copyOfRange(a, 1, a.length), y);
            System.arraycopy(y, 0, y, 1, y.length - 1);
            y[y.length - 1] = output;
            return output;
        }

        private double dot(double[] a, double[] b) {
            double sum = 0;
            for (int i = 0; i < a.length; i++) {
                sum += a[i] * b[i];
            }
            return sum;
        }
    }

    static class SignalGenerator {
        double frequency;
        double sampleRate;
        double duration;

        SignalGenerator(double frequency, double sampleRate, double duration) {
            this.frequency = frequency;
            this.sampleRate = sampleRate;
            this.duration = duration;
        }

        double[] generate() {
            int length = (int) (sampleRate * duration);
            double[] t = new double[length];
            for (int i = 0; i < length; i++) {
                t[i] = i / sampleRate;
            }
            double[] signal = new double[length];
            for (int i = 0; i < length; i++) {
                signal[i] = Math.sin(2 * Math.PI * frequency * t[i]);
            }
            return signal;
        }
    }

    static double[] filterSignal(double[] signal, double[] a, double[] b, double sampleRate, double duration) {
        DigitalFilter filter = new DigitalFilter(a, b);
        double[] filteredSignal = new double[signal.length];
        for (int i = 0; i < signal.length; i++) {
            filteredSignal[i] = filter.process(signal[i]);
        }
        return filteredSignal;
    }

    public static void main(String[] args) {
        double[] coefficientsA = {1, -0.9};
        double[] coefficientsB = {0.5, 0.5};
        SignalGenerator generator = new SignalGenerator(5, 1000, 1);
        double[] signal = generator.generate();
        double[] filteredSignal = filterSignal(signal, coefficientsA, coefficientsB, 1000, 1);
        System.out.println(Arrays.toString(filteredSignal));
    }
}