import java.util.ArrayList;
import java.util.List;

public class sample_2591 {
    public static List<Integer> generate_sequence(int n, int a, int b) {
        List<Integer> sequence = new ArrayList<>();
        sequence.add(a);
        sequence.add(b);
        for (int i = 0; i < n - 2; i++) {
            int next_value = sequence.get(sequence.size() - 1) + sequence.get(sequence.size() - 2);
            sequence.add(next_value);
        }
        return sequence;
    }

    public static int[] analyze_sequence(List<Integer> seq) {
        int max_value = Integer.MIN_VALUE;
        int sum_value = 0;
        for (int value : seq) {
            if (value > max_value) {
                max_value = value;
            }
            sum_value += value;
        }
        int avg_value = sum_value / seq.size();
        return new int[]{max_value, avg_value};
    }

    public static void main(String[] args) {
        int n = 10;
        List<Integer> seq = generate_sequence(n, 0, 1);
        int[] result = analyze_sequence(seq);
        System.out.println("Max Value: " + result[0] + ", Average Value: " + result[1]);
    }
}