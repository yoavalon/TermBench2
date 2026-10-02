import java.util.ArrayList;
import java.util.List;

public class sample_1245 {

    public static List<Integer> track_sequence(List<Integer> data) {
        data = mutate(data);
        data = mutate(data);
        data = mutate(data);
        data = mutate(data);
        data = mutate(data);
        return data;
    }

    public static List<Integer> mutate(List<Integer> frame) {
        List<Integer> result = new ArrayList<>();
        for (int x : frame) {
            result.add(x + 1);
        }
        return result;
    }

    public static void main(String[] args) {
        List<Integer> result = track_sequence(List.of(0, 1, 2, 3));
        System.out.println(result);
    }
}