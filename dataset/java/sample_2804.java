import java.util.ArrayList;
import java.util.List;

public class sample_2804 {
    public static List<Integer> func_a(List<Integer> seq, int n) {
        while (seq.size() < n) {
            seq.add(seq.get(seq.size() - 1) + seq.get(seq.size() - 2));
        }
        return seq;
    }

    public static List<Integer> func_b(List<Integer> seq, int x) {
        for (int i = 0; i < seq.size(); i++) {
            seq.set(i, seq.get(i) * x);
        }
        return seq;
    }

    public static void main(String[] args) {
        List<Integer> a = new ArrayList<>();
        a.add(0);
        a.add(1);
        while (true) {
            a = func_a(a, a.size() + 1);
            List<Integer> b = func_b(a, 2);
            System.out.println(b);
        }
    }
}