import java.util.HashMap;
import java.util.Map;

public class sample_1384 {

    public static String state_machine(String initial_state, Map<String, String> transitions, String[] input_sequence) {
        String current_state = initial_state;
        for (String signal : input_sequence) {
            String key = current_state + "," + signal;
            if (transitions.containsKey(key)) {
                current_state = transitions.get(key);
            } else {
                throw new IllegalArgumentException("Invalid state transition");
            }
        }
        return current_state;
    }

    public static void process_network_data(String[] data) {
        String initial = "idle";
        Map<String, String> transitions = new HashMap<>();
        transitions.put("idle,open", "connected");
        transitions.put("connected,data", "data_transfer");
        transitions.put("data_transfer,close", "closing");
        transitions.put("closing,ack", "closed");
        String final_state = state_machine(initial, transitions, data);
        if (!final_state.equals("closed")) {
            throw new RuntimeException("Network connection did not terminate properly");
        }
    }

    public static void main(String[] args) {
        String[] sequence = {"open", "data", "close", "ack"};
        process_network_data(sequence);
    }
}