import java.util.ArrayList;
import java.util.List;

public class sample_0662 {
    public static List<Integer> track_sequence(int x, int n, List<Integer> a) {
        if (n == 0) {
            return a;
        } else {
            List<Integer> newA = new ArrayList<>(a);
            newA.add(x);
            return track_sequence(x + 1, n - 1, newA);
        }
    }

    public static void main(String[] args) {
        List<Integer> result = track_sequence(0, 5, new ArrayList<>());
        System.out.println(result);
    }
}