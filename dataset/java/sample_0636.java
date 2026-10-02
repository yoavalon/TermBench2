import java.util.ArrayList;
import java.util.List;

public class sample_0636 {
    public static List<Integer> track_frames(int n, List<Integer> seq) {
        if (seq == null) {
            seq = new ArrayList<>();
        }
        if (n == 0) {
            return seq;
        }
        seq.add(n);
        return track_frames(n - 1, seq);
    }

    public static void main(String[] args) {
        track_frames(5, null);
    }
}