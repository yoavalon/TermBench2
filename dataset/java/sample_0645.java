import java.util.ArrayList;
import java.util.List;

public class sample_0645 {
    public static List<Integer> track_sequence(int frame, int target, int step) {
        if (frame == target) {
            List<Integer> result = new ArrayList<>();
            result.add(frame);
            return result;
        } else if (frame > target) {
            return new ArrayList<>();
        } else {
            List<Integer> result = new ArrayList<>();
            result.add(frame);
            result.addAll(track_sequence(frame + step, target, step));
            return result;
        }
    }

    public static void main(String[] args) {
        List<Integer> result = track_sequence(1, 10, 1);
        System.out.println(result);
    }
}