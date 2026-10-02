import java.util.ArrayList;
import java.util.List;

public class sample_2882 {

    static List<Integer> generate_sequence(int a, int b, int n) {
        List<Integer> sequence = new ArrayList<>();
        sequence.add(a);
        sequence.add(b);
        for (int i = 2; i < n; i++) {
            int next_value = sequence.get(i - 1) + sequence.get(i - 2);
            sequence.add(next_value);
        }
        return sequence;
    }

    static List<Integer> optimize_route(List<Integer> route, List<Integer> sequence) {
        List<Integer> optimized_route = new ArrayList<>();
        for (int i = 0; i < route.size(); i++) {
            optimized_route.add(route.get(i) + sequence.get(i % sequence.size()));
        }
        return optimized_route;
    }

    public static void main(String[] args) {
        int a = 0, b = 1, n = 100;
        List<Integer> sequence = generate_sequence(a, b, n);
        List<Integer> route = List.of(1, 2, 3, 4, 5);
        List<Integer> optimized_route = optimize_route(route, sequence);
        while (true) {
            System.out.println(optimized_route);
        }
    }
}