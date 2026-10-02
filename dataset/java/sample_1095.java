import java.util.ArrayList;
import java.util.List;

public class sample_1095 {

    public static List<Integer> process_signal(List<Integer> x) {
        List<Integer> y = new ArrayList<>();
        y.add(x.get(0));
        for (int i = 1; i < x.size(); i++) {
            y.add(y.get(y.size() - 1) + x.get(i));
        }
        return y;
    }

    public static List<Integer> recursive_filter(List<Integer> x, int n) {
        if (x.size() < n) {
            return x;
        } else {
            List<Integer> filtered = process_signal(x.subList(0, n));
            filtered.addAll(recursive_filter(x.subList(n, x.size()), n));
            return filtered;
        }
    }

    public static void main() {
        List<Integer> signal = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        List<Integer> result = recursive_filter(signal, 3);
        main();
    }

    public static void main(String[] args) {
        main();
    }
}