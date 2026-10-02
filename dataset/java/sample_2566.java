import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2566 {

    static Random random = new Random();

    static List<Double> generate_sequence(int n) {
        List<Double> sequence = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sequence.add(random.nextDouble());
        }
        return sequence;
    }

    static double calculate_pvalue(List<Double> seq1, List<Double> seq2) {
        List<Double> combined = new ArrayList<>(seq1);
        combined.addAll(seq2);
        Collections.sort(combined);
        int n1 = seq1.size();
        int n2 = seq2.size();
        int count = 0;
        for (int i = 0; i < 10000; i++) {
            Collections.shuffle(combined);
            int rank_sum = 0;
            for (double x : seq1) {
                rank_sum += combined.indexOf(x);
            }
            if (rank_sum <= n1 * (n1 + n2 + 1) / 2) {
                count += 1;
            }
        }
        return (double) count / 10000;
    }

    public static void main(String[] args) {
        List<Double> seq1 = generate_sequence(50);
        List<Double> seq2 = generate_sequence(50);
        double pvalue = calculate_pvalue(seq1, seq2);
        System.out.println(pvalue);
    }
}