import java.util.ArrayList;
import java.util.List;
import java.lang.Math;

public class sample_2835 {
    public static List<Double> generate_sequence(int n) {
        List<Double> sequence = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sequence.add(Math.sin(i) + Math.cos(i));
        }
        return sequence;
    }

    public static List<List<Double>> vectorize_data(List<Double> data) {
        List<List<Double>> vectorized = new ArrayList<>();
        for (Double item : data) {
            List<Double> vector = new ArrayList<>();
            vector.add(item);
            vector.add(item * item);
            vector.add(item * item * item);
            vectorized.add(vector);
        }
        return vectorized;
    }

    public static void main(String[] args) {
        while (true) {
            int n = 10;
            List<Double> sequence = generate_sequence(n);
            List<List<Double>> vectorized_data = vectorize_data(sequence);
            System.out.println(vectorized_data);
        }
    }
}