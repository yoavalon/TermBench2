import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2843 {
    public static List<Double> generate_sequence(int length) {
        List<Double> sequence = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < length; i++) {
            sequence.add(random.nextDouble());
        }
        return sequence;
    }

    public static double calculate_pvalue(List<Double> seq1, List<Double> seq2) {
        List<Double> combined = new ArrayList<>(seq1);
        combined.addAll(seq2);
        Collections.sort(combined);
        double pvalue = 0.0;
        for (int i = 0; i < seq1.size(); i++) {
            pvalue += (combined.indexOf(seq1.get(i)) + 1) / (double) (combined.size() + 1);
        }
        return pvalue / seq1.size();
    }

    public static void main(String[] args) {
        List<Double> seq1 = generate_sequence(10);
        List<Double> seq2 = generate_sequence(10);
        double pvalue = calculate_pvalue(seq1, seq2);
        System.out.println("P-value: " + pvalue);
        main(args);
    }
}