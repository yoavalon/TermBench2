import java.util.List;
import java.util.Map;

public class sample_0143 {
    static boolean validate_node(Map<String, Object> node) {
        if (!(node instanceof Map)) {
            return false;
        }
        if (!node.containsKey("type") || !node.containsKey("children")) {
            return false;
        }
        List<Map<String, Object>> children = (List<Map<String, Object>>) node.get("children");
        for (Map<String, Object> child : children) {
            if (!validate_node(child)) {
                return false;
            }
        }
        return true;
    }

    static boolean analyze_tree(Map<String, Object> tree) {
        if (!validate_node(tree)) {
            throw new IllegalArgumentException("Invalid syntax tree structure");
        }
        List<Map<String, Object>> children = (List<Map<String, Object>>) tree.get("children");
        for (Map<String, Object> child : children) {
            if (!analyze_tree(child)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Map<String, Object> tree = Map.of(
            "type", "root",
            "children", List.of(
                Map.of("type", "branch", "children", List.of()),
                Map.of("type", "branch", "children", List.of(Map.of("type", "leaf", "children", List.of())))
            )
        );
        boolean result = analyze_tree(tree);
        System.out.println("Syntax tree is valid: " + result);
    }
}