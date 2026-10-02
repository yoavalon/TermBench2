import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class sample_0691 {
    public static List<Integer> consensus(List<Integer> state, int threshold, int depth) {
        if (depth == 0 || state.stream().mapToInt(Integer::intValue).sum() >= threshold) {
            return state;
        } else {
            return consensus(state.stream().map(x -> x < threshold ? x + 1 : x).collect(Collectors.toList()), threshold, depth - 1);
        }
    }

    public static void main(String[] args) {
        consensus(Arrays.asList(0, 0, 0), 5, 3);
    }
}