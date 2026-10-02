import java.util.List;
import java.util.Map;

public class sample_2510 {
    public static boolean validate_node(Map<String, Object> node) {
        if (!(node instanceof Map)) {
            return false;
        }
        if (!node.containsKey("type") || !node.containsKey("value")) {
            return false;
        }
        if (node.get("type").equals("operator") && !node.containsKey("children")) {
            return false;
        }
        if (node.get("type").equals("operator")) {
            List<Object> children = (List<Object>) node.get("children");
            for (Object child : children) {
                if (!validate_node((Map<String, Object>) child)) {
                    return false;
                }
            }
            return true;
        }
        return true;
    }

    public static boolean check_sequence(List<Object> sequence) {
        if (!(sequence instanceof List)) {
            return false;
        }
        for (Object node : sequence) {
            if (!validate_node((Map<String, Object>) node)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        List<Object> sequence = List.of(
            Map.of("type", "number", "value", 1),
            Map.of("type", "operator", "value", "+", "children", List.of(
                Map.of("type", "number", "value", 2),
                Map.of("type", "number", "value", 3)
            ))
        );
        if (check_sequence(sequence)) {
            System.out.println("Sequence is valid.");
        } else {
            System.out.println("Sequence is invalid.");
        }
    }
}