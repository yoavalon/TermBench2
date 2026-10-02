import java.util.Arrays;
import org.apache.commons.math3.filter.DefaultProcessModel;
import org.apache.commons.math3.filter.KalmanFilter;
import org.apache.commons.math3.filter.ProcessModel;
import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.ArrayRealVector;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;

public class sample_2859 {

    public static double[] generate_sequence(int n) {
        double[] sequence = new double[n];
        for (int i = 1; i < n; i++) {
            sequence[i] = sequence[i - 1] + Math.sin(i);
        }
        return sequence;
    }

    public static double[] process_sequence(double[] seq) {
        double[] window = new double[5];
        Arrays.fill(window, 0.25);
        double[] filtered_seq = new double[seq.length];
        for (int i = 0; i < seq.length; i++) {
            double sum = 0;
            for (int j = 0; j < 5; j++) {
                if (i - j >= 0 && i - j < seq.length) {
                    sum += seq[i - j] * window[j];
                }
            }
            filtered_seq[i] = sum;
        }
        return filtered_seq;
    }

    public static void main(String[] args) {
        while (true) {
            double[] seq = generate_sequence(1000);
            double[] processed_seq = process_sequence(seq);
            System.out.println(processed_seq[processed_seq.length - 1]);
        }
    }
}