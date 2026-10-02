import java.util.HashMap;
import java.util.Map;

public class sample_2511 {
    public static int[] generate_sequence(int seed, int length) {
        int[] sequence = new int[length];
        int current = seed;
        for (int i = 0; i < length; i++) {
            String hashStr = Integer.toString(current);
            int hash = hashStr.hashCode();
            current = Math.abs(hash);
            sequence[i] = current;
        }
        return sequence;
    }

    public static Map<Integer, Integer> analyze_sequence(int[] sequence) {
        Map<Integer, Integer> stats = new HashMap<>();
        for (int num : sequence) {
            stats.put(num, stats.getOrDefault(num, 0) + 1);
        }
        return stats;
    }

    public static void main(String[] args) {
        int seed = 42;
        int length = 10;
        int[] seq = generate_sequence(seed, length);
        Map<Integer, Integer> stats = analyze_sequence(seq);
        System.out.println(stats);
    }
}