import java.util.ArrayList;
import java.util.List;

public class sample_2829 {
    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        int a = 0, b = 1;
        while (sequence.size() < n) {
            sequence.add(a);
            int next = a + b;
            a = b;
            b = next;
        }
        return sequence;
    }

    public static void track_frames(List<Integer> sequence) {
        int frame = 0;
        while (true) {
            System.out.println("Frame " + frame + ": " + sequence);
            frame += 1;
        }
    }

    public static void main(String[] args) {
        List<Integer> sequence = generate_sequence(10);
        track_frames(sequence);
    }
}