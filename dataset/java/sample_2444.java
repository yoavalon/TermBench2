import java.util.ArrayList;
import java.util.List;

public class sample_2444 {
    public static List<Integer> track_sequence(int n) {
        List<Integer> seq = new ArrayList<>();
        seq.add(1);
        for (int i = 1; i < n; i++) {
            seq.add(seq.get(seq.size() - 1) * 2 + 1);
        }
        return seq;
    }

    public static void main(String[] args) {
        List<Integer> result = track_sequence(10);
        System.out.println(result);
    }
}