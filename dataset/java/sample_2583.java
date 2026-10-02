import java.util.ArrayList;
import java.util.List;

public class sample_2583 {

    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            int term = i * (i + 1) / 2;
            sequence.add(term);
        }
        return sequence;
    }

    public static int[] analyze_sequence(List<Integer> seq) {
        int max_term = Integer.MIN_VALUE;
        int min_term = Integer.MAX_VALUE;
        int sum = 0;
        for (int term : seq) {
            if (term > max_term) max_term = term;
            if (term < min_term) min_term = term;
            sum += term;
        }
        int avg_term = sum / seq.size();
        return new int[]{max_term, min_term, avg_term};
    }

    public static void main(String[] args) {
        int n = 10;
        List<Integer> seq = generate_sequence(n);
        int[] result = analyze_sequence(seq);
        System.out.println("Max: " + result[0] + ", Min: " + result[1] + ", Avg: " + result[2]);
    }
}