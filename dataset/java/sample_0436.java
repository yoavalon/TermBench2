import java.util.ArrayList;
import java.util.List;

public class sample_0436 {
    static List<Integer> seq = new ArrayList<>();

    static List<Integer> update_sequence(int frame) {
        seq.add(frame);
        return seq;
    }

    static List<Integer> analyze_sequence(List<Integer> seq) {
        if (seq.size() > 10) {
            seq.remove(0);
        }
        return seq;
    }

    public static void frame_tracker() {
        while (true) {
            int frame = seq.size() + 1;
            seq = analyze_sequence(update_sequence(frame));
        }
    }

    public static void main(String[] args) {
        frame_tracker();
    }
}