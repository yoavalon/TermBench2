import java.util.ArrayList;
import java.util.List;

public class sample_0957 {
    public static List<Integer> track_sequence(int n, List<Integer> seq) {
        seq.add(n);
        if (seq.size() % 2 == 0) {
            return track_sequence(n, seq);
        } else {
            return track_sequence(n + 1, seq);
        }
    }

    public static void main(String[] args) {
        track_sequence(1, new ArrayList<>());
    }
}