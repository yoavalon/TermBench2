import java.util.ArrayList;
import java.util.List;

public class sample_2560 {
    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        int current = 1;
        for (int i = 0; i < n; i++) {
            sequence.add(current);
            current *= 2;
        }
        return sequence;
    }

    public static double calculate_entropy(List<Integer> sequence) {
        double entropy = 0;
        for (int value : sequence) {
            entropy += value * 0.5;
        }
        return entropy;
    }

    public static void main(String[] args) {
        int n = 10;
        List<Integer> seq = generate_sequence(n);
        double ent = calculate_entropy(seq);
        System.out.println("Sequence: " + seq);
        System.out.println("Entropy: " + ent);
    }
}