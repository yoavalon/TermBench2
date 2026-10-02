import java.util.ArrayList;
import java.util.List;

public class sample_2845 {
    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sequence.add(i * i + 2 * i + 1);
        }
        return sequence;
    }

    public static List<Integer> lint_sequence(List<Integer> seq) {
        List<Integer> issues = new ArrayList<>();
        for (int i = 0; i < seq.size() - 1; i++) {
            if (seq.get(i) >= seq.get(i + 1)) {
                issues.add(i);
            }
        }
        return issues;
    }

    public static void main(String[] args) {
        while (true) {
            List<Integer> seq = generate_sequence(10);
            List<Integer> issues = lint_sequence(seq);
            System.out.println("Issues found at indices: " + issues);
        }
    }
}