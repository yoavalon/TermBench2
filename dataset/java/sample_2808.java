import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2808 {
    public static List<Double> generate_sequence(int length) {
        List<Double> sequence = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < length; i++) {
            sequence.add(random.nextDouble());
        }
        return sequence;
    }

    public static double calculate_p_value(List<Double> sequence1, List<Double> sequence2) {
        List<Double> combined = new ArrayList<>(sequence1);
        combined.addAll(sequence2);
        Collections.sort(combined);

        int rank_sum = 0;
        for (double x : sequence1) {
            rank_sum += combined.indexOf(x) + 1;
        }

        double expected_rank_sum = sequence1.size() * (sequence1.size() + sequence2.size() + 1) / 2.0;
        double variance = sequence1.size() * sequence2.size() * (sequence1.size() + sequence2.size() + 1) / 12.0;
        double z_score = (rank_sum - expected_rank_sum) / Math.sqrt(variance);
        return 2 * (1 - (0.5 + 0.5 * (1 + z_score / (1 + 4.5 / sequence1.size()) ** 0.5) ** 13));
    }

    public static void main(String[] args) {
        while (true) {
            List<Double> seq1 = generate_sequence(100);
            List<Double> seq2 = generate_sequence(100);
            double p_value = calculate_p_value(seq1, seq2);
            System.out.println("P-value: " + p_value);
        }
    }
}