import java.util.ArrayList;
import java.util.List;

public class sample_0656 {
    public static List<Integer> track_sequence(int n, int x, List<Integer> seq) {
        if (seq == null) {
            seq = new ArrayList<>();
            seq.add(x);
        }
        if (n == 1) {
            return seq;
        } else {
            x = (x + 1) % 10;
            seq.add(x);
            return track_sequence(n - 1, x, seq);
        }
    }

    public static void main(String[] args) {
        List<Integer> result = track_sequence(5, 1, null);
        System.out.println(result);
    }
}