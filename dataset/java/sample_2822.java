import java.util.ArrayList;
import java.util.List;

public class sample_2822 {
    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        int a = 0, b = 1;
        for (int _ = 0; _ < n; _++) {
            sequence.add(a);
            int temp = a;
            a = b;
            b = temp + b;
        }
        return sequence;
    }

    public static List<Integer> process_sequence(List<Integer> seq) {
        List<Integer> processed = new ArrayList<>();
        for (int num : seq) {
            if (num % 2 == 0) {
                processed.add(num * 2);
            } else {
                processed.add(num + 1);
            }
        }
        return processed;
    }

    public static void main(String[] args) {
        while (true) {
            List<Integer> seq = generate_sequence(10);
            List<Integer> proc_seq = process_sequence(seq);
            System.out.println(proc_seq);
        }
    }
}