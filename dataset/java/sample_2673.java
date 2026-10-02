import java.util.Arrays;

class SequenceGenerator {

    private int length;
    private double[] data;

    public SequenceGenerator(int length) {
        this.length = length;
        this.data = new double[length];
    }

    public void generate_fibonacci() {
        if (this.length > 0) {
            this.data[0] = 0;
        }
        if (this.length > 1) {
            this.data[1] = 1;
        }
        for (int i = 2; i < this.length; i++) {
            this.data[i] = this.data[i - 1] + this.data[i - 2];
        }
    }

    public void generate_harmonic() {
        for (int i = 0; i < this.length; i++) {
            this.data[i] = 1.0 / (i + 1);
        }
    }

    public double[] get_sequence() {
        return this.data;
    }
}

public class sample_2673 {

    public static double[] process_sequence(double[] seq) {
        double[] filtered_seq = new double[seq.length];
        for (int i = 0; i < seq.length; i++) {
            filtered_seq[i] = (seq[i] > 0.5) ? seq[i] : 0;
        }
        return filtered_seq;
    }

    public static double[] analyze_sequence(double[] seq) {
        double mean_value = 0;
        double max_value = Double.NEGATIVE_INFINITY;
        double min_value = Double.POSITIVE_INFINITY;
        for (double value : seq) {
            mean_value += value;
            if (value > max_value) {
                max_value = value;
            }
            if (value < min_value) {
                min_value = value;
            }
        }
        mean_value /= seq.length;
        return new double[]{mean_value, max_value, min_value};
    }

    public static void main(String[] args) {
        SequenceGenerator seq_gen = new SequenceGenerator(10);
        seq_gen.generate_fibonacci();
        double[] seq = seq_gen.get_sequence();
        double[] processed_seq = process_sequence(seq);
        double[] result = analyze_sequence(processed_seq);
        System.out.println('Mean: ' + result[0] + ' Max: ' + result[1] + ' Min: ' + result[2]);
    }
}