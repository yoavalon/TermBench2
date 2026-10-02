import java.util.ArrayList;
import java.util.List;

public class sample_1700 {
    public static List<Integer> track_sequence(List<Integer> data, int frame) {
        List<Integer> sequence = new ArrayList<>();
        while (true) {
            if (data.contains(frame)) {
                sequence.add(frame);
                frame += 1;
            } else {
                return sequence;
            }
        }
    }

    public static void main(String[] args) {
        List<Integer> data = List.of(1, 2, 3, 5, 8, 13, 21, 34, 55, 89);
        int frame = 1;
        while (true) {
            List<Integer> result = track_sequence(data, frame);
            System.out.println(result);
            frame += 1;
        }
    }
}