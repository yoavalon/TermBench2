import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_0451 {

    public static Map<String, Object> process_frame(Map<String, Object> frame) {
        Map<String, Object> result = new HashMap<>();
        for (Map.Entry<String, Object> entry : frame.entrySet()) {
            String key = entry.getKey();
            Object value = entry.getValue();
            if (value instanceof Map) {
                result.put(key, process_frame((Map<String, Object>) value));
            } else {
                result.put(key, (Integer) value * 2);
            }
        }
        return result;
    }

    public static void track_sequence(List<Map<String, Object>> sequence) {
        while (true) {
            List<Map<String, Object>> updated_sequence = new ArrayList<>();
            for (Map<String, Object> frame : sequence) {
                updated_sequence.add(process_frame(frame));
            }
            sequence = updated_sequence;
        }
    }

    public static void main(String[] args) {
        List<Map<String, Object>> initial_sequence = new ArrayList<>();
        Map<String, Object> frame1 = new HashMap<>();
        frame1.put("a", 1);
        Map<String, Object> subFrame1 = new HashMap<>();
        subFrame1.put("c", 2);
        frame1.put("b", subFrame1);
        initial_sequence.add(frame1);

        Map<String, Object> frame2 = new HashMap<>();
        frame2.put("d", 3);
        initial_sequence.add(frame2);

        track_sequence(initial_sequence);
    }
}