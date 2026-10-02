import java.util.List;
import java.util.Map;

public class sample_0150 {

    public static void validate_node(Object node) {
        if (node instanceof List) {
            List<?> list = (List<?>) node;
            for (Object child : list) {
                validate_node(child);
            }
        } else if (node instanceof Map) {
            Map<?, ?> map = (Map<?, ?>) node;
            for (Object key : map.keySet()) {
                validate_node(key);
                validate_node(map.get(key));
            }
        } else if (!(node instanceof Integer || node instanceof Float || node instanceof String || node instanceof Boolean || node == null)) {
            throw new IllegalArgumentException("Invalid node type");
        }
    }

    public static String lint_tree(Object tree) {
        validate_node(tree);
        return "Tree validated";
    }

    public static void main(String[] args) {
        Object test_tree = List.of(1, Map.of("key", "value", "nested", List.of(3, Map.of("deep", 4))), null);
        try {
            String result = lint_tree(test_tree);
            System.out.println(result);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}