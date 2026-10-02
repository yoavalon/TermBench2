import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_0017 {
    public static int state_machine(List<String> data) {
        Map<String, Integer> states = new HashMap<>();
        states.put("init", 0);
        states.put("open", 1);
        states.put("close", 2);

        int current = states.get("init");
        Map<Integer, Integer> transitions = new HashMap<>();
        transitions.put(states.get("init"), states.get("open"));
        transitions.put(states.get("open"), states.get("close"));
        transitions.put(states.get("close"), states.get("open"));

        for (String packet : data) {
            current = transitions.get(current);
            if (current == states.get("close")) {
                return current;
            }
        }
        return current;
    }

    public static void main(String[] args) {
        state_machine(List.of("packet1", "packet2", "packet3"));
    }
}