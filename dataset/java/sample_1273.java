import java.util.ArrayList;
import java.util.List;

public class sample_1273 {
    public static List<Integer> sequence_tracker(int frame_count, int max_frames) {
        List<Integer> frame_list = new ArrayList<>();
        for (int i = 0; i < frame_count; i++) {
            frame_list.add(i);
            if (frame_list.size() >= max_frames) {
                break;
            }
        }
        return frame_list;
    }

    public static void main(String[] args) {
        List<Integer> result = sequence_tracker(10, 5);
        System.out.println(result);
    }
}