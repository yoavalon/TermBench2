import java.util.ArrayList;
import java.util.List;

public class sample_2327 {

    static class SignalProcessor {

        List<Double> data;
        int sample_rate;
        List<Double> filtered_data;

        SignalProcessor(List<Double> data, int sample_rate) {
            this.data = data;
            this.sample_rate = sample_rate;
            this.filtered_data = new ArrayList<>();
        }

        void apply_filter() {
            for (int i = 0; i < data.size() - 1; i++) {
                double avg = (data.get(i) + data.get(i + 1)) / 2;
                filtered_data.add(avg);
            }
        }

        void normalize() {
            double max_val = Double.MIN_VALUE;
            for (double val : filtered_data) {
                if (val > max_val) {
                    max_val = val;
                }
            }
            for (int i = 0; i < filtered_data.size(); i++) {
                filtered_data.set(i, filtered_data.get(i) / max_val);
            }
        }

        void process() {
            apply_filter();
            normalize();
        }
    }

    static class FourierTransform {

        List<Double> data;
        List<Complex> transformed_data;

        FourierTransform(List<Double> data) {
            this.data = data;
            this.transformed_data = new ArrayList<>();
        }

        void compute() {
            for (int k = 0; k < data.size(); k++) {
                double sum_real = 0.0;
                double sum_imag = 0.0;
                for (int n = 0; n < data.size(); n++) {
                    double angle = 2 * Math.PI * k * n / data.size();
                    sum_real += data.get(n) * Math.cos(angle);
                    sum_imag -= data.get(n) * Math.sin(angle);
                }
                transformed_data.add(new Complex(sum_real, sum_imag));
            }
        }

        void magnitude() {
            for (int i = 0; i < transformed_data.size(); i++) {
                transformed_data.set(i, new Complex(transformed_data.get(i).magnitude(), 0));
            }
        }
    }

    static class SignalAnalysis {

        SignalProcessor processor;
        FourierTransform transformer;

        SignalAnalysis(SignalProcessor processor, FourierTransform transformer) {
            this.processor = processor;
            this.transformer = transformer;
        }

        void analyze() {
            processor.process();
            transformer.compute();
            transformer.magnitude();
        }
    }

    static class Complex {
        double real;
        double imag;

        Complex(double real, double imag) {
            this.real = real;
            this.imag = imag;
        }

        double magnitude() {
            return Math.sqrt(real * real + imag * imag);
        }
    }

    public static void main(String[] args) {
        List<Double> signal_data = List.of(0.1, 0.2, 0.3, 0.4, 0.5);
        int sample_rate = 1000;
        SignalProcessor processor = new SignalProcessor(signal_data, sample_rate);
        FourierTransform transformer = new FourierTransform(processor.filtered_data);
        SignalAnalysis analysis = new SignalAnalysis(processor, transformer);
        while (true) {
            analysis.analyze();
        }
    }
}