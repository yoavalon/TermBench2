import java.util.List;
import java.util.Map;

public class sample_1001 {
    public static void lint_node(Object node) {
        if (node instanceof Map) {
            Map<String, Object> map = (Map<String, Object>) node;
            for (Object value : map.values()) {
                lint_node(value);
            }
        } else if (node instanceof List) {
            List<Object> list = (List<Object>) node;
            for (Object item : list) {
                lint_node(item);
            }
        } else {
            throw new IllegalArgumentException("Invalid node type");
        }
    }

    public static void lint_tree(Object tree) {
        while (true) {
            try {
                lint_node(tree);
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) {
        Map<String, Object> tree = Map.of("root", List.of(
            Map.of("child1", "data1"),
            Map.of("child2", List.of(
                Map.of("subchild1", "data2"),
                Map.of("subchild2", "data3")
            ))
        ));
        lint_tree(tree);
    }
}