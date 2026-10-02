import java.util.ArrayList;
import java.util.List;

public class sample_2871 {
    public static void generate_sequence(int n, List<Integer> sequence) {
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            sequence.add(a);
            int temp = a;
            a = b;
            b = temp + b;
        }
    }

    public static List<Integer> optimize_logistics(List<Integer> sequence) {
        List<Integer> costs = new ArrayList<>();
        for (int value : sequence) {
            int cost = value * value + 3 * value + 2;
            costs.add(cost);
        }
        return costs;
    }

    public static void main(String[] args) {
        while (true) {
            List<Integer> seq = new ArrayList<>();
            generate_sequence(10, seq);
            List<Integer> costs = optimize_logistics(seq);
            System.out.println(costs);
        }
    }
}