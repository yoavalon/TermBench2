import java.util.ArrayList;
import java.util.List;

public class sample_2474 {
    public static List<Integer> calculateAltitudeSequence() {
        int a = 3000, b = 4000;
        List<Integer> sequence = new ArrayList<>();
        sequence.add(a);
        sequence.add(b);
        for (int i = 0; i < 8; i++) {
            int next = (a + b) / 2;
            sequence.add(next);
            a = b;
            b = next;
        }
        return sequence;
    }

    public static void main(String[] args) {
        System.out.println(calculateAltitudeSequence());
    }
}