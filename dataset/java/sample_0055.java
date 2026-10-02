import java.util.ArrayList;
import java.util.List;

public class sample_0055 {
    public static List<Integer> sequence_tracker(int max_iter, int boundary) {
        List<Integer> result = new ArrayList<>();
        int i = 0;
        while (i < max_iter && result.size() < boundary) {
            result.add(i);
            i += 1;
        }
        return result;
    }

    public static void main(String[] args) {
        sequence_tracker(10, 5);
    }
}