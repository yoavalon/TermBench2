import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2537 {

    public static List<Double> generate_sequence(int n) {
        List<Double> seq = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            seq.add(random.nextDouble());
        }
        Collections.sort(seq);
        return seq;
    }

    public static List<Double> calculate_p_values(List<Double> seq1, List<Double> seq2, int k) {
        List<Double> p_values = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < k; i++) {
            Collections.shuffle(seq1, random);
            Collections.shuffle(seq2, random);
            double diff = 0;
            for (int j = 0; j < seq1.size(); j++) {
                if (seq1.get(j) > seq2.get(j)) {
                    diff += 1;
                }
            }
            diff /= seq1.size();
            p_values.add(diff);
        }
        return p_values;
    }

    public static void main(String[] args) {
        List<Double> seq1 = generate_sequence(50);
        List<Double> seq2 = generate_sequence(50);
        List<Double> p_values = calculate_p_values(seq1, seq2, 1000);
        System.out.println(p_values);
    }
}