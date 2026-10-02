import java.util.List;

public class sample_0092 {
    public static String analyze_network_connections(List<String> connections, List<String> states, List<List<String>> transitions) {
        String current_state = states.get(0);
        for (String connection : connections) {
            for (List<String> transition : transitions) {
                if (transition.get(0).equals(current_state) && transition.get(1).equals(connection)) {
                    current_state = transition.get(2);
                    break;
                }
            }
        }
        return current_state;
    }

    public static void main(String[] args) {
        List<String> connections = List.of("open", "data", "close");
        List<String> states = List.of("idle", "active", "closed");
        List<List<String>> transitions = List.of(
            List.of("idle", "open", "active"),
            List.of("active", "data", "active"),
            List.of("active", "close", "closed")
        );
        String result = analyze_network_connections(connections, states, transitions);
        System.out.println(result);
    }
}