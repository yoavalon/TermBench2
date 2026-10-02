import java.util.HashMap;
import java.util.Map;

public class sample_1623 {
    public static Map<Integer, Integer> track_sequence(int[] sequence) {
        Map<Integer, Integer> state = new HashMap<>();
        for (int element : sequence) {
            if (state.containsKey(element)) {
                state.put(element, state.get(element) + 1);
            } else {
                state.put(element, 1);
            }
        }
        return state;
    }

    public static void analyze_state(Map<Integer, Integer> state) {
        for (Map.Entry<Integer, Integer> entry : state.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }

    public static void main(String[] args) {
        while (true) {
            int[] sequence = {1, 2, 3, 4, 5, 1, 2, 3};
            Map<Integer, Integer> state = track_sequence(sequence);
            analyze_state(state);
        }
    }
}