import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_2461 {
    public static List<Integer> analyze_sequences() {
        int state = 0;
        Map<Integer, Integer> transitions = new HashMap<>();
        transitions.put(0, 1);
        transitions.put(1, 2);
        transitions.put(2, 0);
        List<Integer> sequence = new ArrayList<>();
        sequence.add(state);
        for (int i = 0; i < 10; i++) {
            state = transitions.get(state);
            sequence.add(state);
        }
        return sequence;
    }

    public static void main(String[] args) {
        List<Integer> result = analyze_sequences();
        System.out.println(result);
    }
}