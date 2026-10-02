import java.util.ArrayList;
import java.util.List;

public class sample_2558 {
    public static List<Integer> generate_sequence(int n) {
        List<Integer> seq = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            seq.add(i * (i + 1));
        }
        return seq;
    }

    public static int process_sequence(List<Integer> seq) {
        int total = 0;
        for (int num : seq) {
            total += num;
        }
        return total;
    }

    public static void main(String[] args) {
        int n = 10;
        List<Integer> seq = generate_sequence(n);
        int result = process_sequence(seq);
        System.out.println(result);
    }
}