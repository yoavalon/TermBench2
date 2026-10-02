import java.util.ArrayList;
import java.util.List;

public class sample_0612 {
    public static List<Integer> track_sequence(int n, List<Integer> seq) {
        if (n == 0) {
            return seq;
        }
        seq.add(n);
        return track_sequence(n - 1, seq);
    }

    public static void main(String[] args) {
        List<Integer> result = track_sequence(5, new ArrayList<>());
        System.out.println(result);
    }
}