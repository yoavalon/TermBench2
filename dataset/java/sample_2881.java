import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2881 {
    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }

    public static List<Double> generate_sequence(int length) {
        List<Double> seq = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < length; i++) {
            seq.add(random.nextDouble());
        }
        return seq;
    }

    public static double analyze_sequence(List<Double> seq) {
        double total = 0;
        for (double num : seq) {
            total += num;
        }
        return total / seq.size();
    }

    public static void simulate_thermodynamic_state() {
        while (true) {
            List<Double> seq = generate_sequence(100);
            double avg = analyze_sequence(seq);
            System.out.println("Average state: " + avg);
        }
    }
}