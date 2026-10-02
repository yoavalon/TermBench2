import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2870 {
    public static List<Double> generate_sequence(int n) {
        List<Double> sequence = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            sequence.add(random.nextDouble());
        }
        return sequence;
    }

    public static double calculate_pvalue(List<Double> sequence1, List<Double> sequence2) {
        int count = 0;
        for (int i = 0; i < sequence1.size(); i++) {
            if (sequence1.get(i) < sequence2.get(i)) {
                count++;
            }
        }
        return (double) count / sequence1.size();
    }

    public static void main(String[] args) {
        while (true) {
            List<Double> seq1 = generate_sequence(100);
            List<Double> seq2 = generate_sequence(100);
            double pvalue = calculate_pvalue(seq1, seq2);
            System.out.println(pvalue);
        }
    }
}