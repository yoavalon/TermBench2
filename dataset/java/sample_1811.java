import java.util.HashMap;
import java.util.Map;

public class sample_1811 {
    public static boolean process_connections(String[] states, Map<String, String> transitions, String start, String end) {
        String current = start;
        for (int i = 0; i < states.length * 2; i++) {
            if (current.equals(end)) {
                break;
            }
            current = transitions.getOrDefault(current, current);
        }
        return current.equals(end);
    }

    public static void main(String[] args) {
        String[] states = {"A", "B", "C"};
        Map<String, String> transitions = new HashMap<>();
        transitions.put("A", "B");
        transitions.put("B", "C");
        transitions.put("C", "A");
        boolean result = process_connections(states, transitions, "A", "C");
        System.out.println(result);
    }
}