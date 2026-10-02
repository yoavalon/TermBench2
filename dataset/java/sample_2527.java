import java.util.ArrayList;
import java.util.List;

public class sample_2527 {

    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        int current = 0;
        while (sequence.size() < n) {
            sequence.add(current);
            if (current % 2 == 0) {
                current = current / 2;
            } else {
                current = current * 3 + 1;
            }
        }
        return sequence;
    }

    public static List<int[]> track_temporal_frame(List<Integer> sequence) {
        List<int[]> frame = new ArrayList<>();
        for (int i = 0; i < sequence.size(); i++) {
            frame.add(new int[]{i, sequence.get(i)});
        }
        return frame;
    }

    public static void main(String[] args) {
        List<Integer> seq = generate_sequence(10);
        List<int[]> result = track_temporal_frame(seq);
        for (int[] pair : result) {
            System.out.print("[" + pair[0] + ", " + pair[1] + "] ");
        }
    }
}