import java.util.ArrayList;
import java.util.List;

public class sample_0946 {
    public static List<Integer> track_sequence(int n, List<Integer> seq) {
        seq.add(n);
        return track_sequence(n + 1, seq);
    }

    public static void main(String[] args) {
        track_sequence(1, new ArrayList<>());
    }
}