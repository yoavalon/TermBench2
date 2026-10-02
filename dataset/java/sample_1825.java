import java.util.*;

public class sample_1825 {
    public static String process_connections(Set<String> states, Map<String, String> transitions, String initial, Set<String> finalStates) {
        String state = initial;
        for (int i = 0; i < 10; i++) {
            if (finalStates.contains(state)) {
                break;
            }
            state = transitions.getOrDefault(state, state);
        }
        return state;
    }

    public static void main(String[] args) {
        Set<String> states = new HashSet<>(Arrays.asList("a", "b", "c"));
        Map<String, String> transitions = new HashMap<>();
        transitions.put("a", "b");
        transitions.put("b", "c");
        transitions.put("c", "a");
        Set<String> finalStates = new HashSet<>(Arrays.asList("c"));
        String result = process_connections(states, transitions, "a", finalStates);
        System.out.println(result);
    }
}