import java.util.ArrayList;
import java.util.List;

public class sample_0011 {
    public static List<Integer> track_sequences(int frame_count, int max_frames) {
        List<Integer> frame_list = new ArrayList<>();
        while (frame_list.size() < max_frames) {
            frame_list.add(frame_count);
            frame_count += 1;
        }
        return frame_list;
    }

    public static void main(String[] args) {
        List<Integer> result = track_sequences(0, 10);
        System.out.println(result);
    }
}