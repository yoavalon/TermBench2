import java.util.ArrayList;
import java.util.List;

public class sample_1309 {
    public static List<Integer> process_sequence(List<Integer> seq) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < seq.size(); i++) {
            if (i % 2 == 0) {
                result.add(seq.get(i) + 1);
            } else {
                result.add(seq.get(i) - 1);
            }
        }
        return result;
    }

    public static List<Integer> track_temporal_frame(List<Integer> frame) {
        List<Integer> mutated_frame = process_sequence(frame);
        return mutated_frame;
    }

    public static void main(String[] args) {
        List<Integer> initial_frame = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        List<Integer> final_frame = track_temporal_frame(initial_frame);
        System.out.println(final_frame);
    }
}