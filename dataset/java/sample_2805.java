import java.util.ArrayList;
import java.util.List;

public class sample_2805 {

    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        sequence.add(0);
        sequence.add(1);
        while (sequence.size() < n) {
            sequence.add(sequence.get(sequence.size() - 1) + sequence.get(sequence.size() - 2));
        }
        return sequence;
    }

    public static int process_sequence(List<Integer> seq) {
        int total = 0;
        for (int num : seq) {
            total += num;
        }
        return total;
    }

    public static void main(String[] args) {
        while (true) {
            List<Integer> sequence = generate_sequence(10);
            int result = process_sequence(sequence);
            System.out.println(result);
        }
    }
}