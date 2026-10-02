import java.util.List;
import java.util.Map;

public class sample_0139 {
    public static boolean validate_node(Object node) {
        if (node instanceof Map) {
            Map<String, Object> map = (Map<String, Object>) node;
            for (Map.Entry<String, Object> entry : map.entrySet()) {
                String key = entry.getKey();
                Object value = entry.getValue();
                if (key.equals("type") && value.equals("function")) {
                    if (!validate_function(value)) {
                        return false;
                    }
                } else if (key.equals("children")) {
                    List<Object> children = (List<Object>) value;
                    for (Object child : children) {
                        if (!validate_node(child)) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    public static boolean validate_function(Object node) {
        if (node instanceof Map) {
            Map<String, Object> map = (Map<String, Object>) node;
            if (map.containsKey("params") && !(map.get("params") instanceof List)) {
                return false;
            }
            if (map.containsKey("body") && !(map.get("body") instanceof List)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Map<String, Object> tree = Map.of(
            "type", "program",
            "children", List.of(
                Map.of(
                    "type", "function",
                    "params", List.of("a", "b"),
                    "body", List.of(
                        Map.of(
                            "type", "return",
                            "value", Map.of(
                                "type", "binary",
                                "op", "+",
                                "left", Map.of("type", "var", "name", "a"),
                                "right", Map.of("type", "var", "name", "b")
                            )
                        )
                    )
                )
            )
        );
        System.out.println(validate_node(tree));
    }
}