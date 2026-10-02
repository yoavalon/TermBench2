import java.util.List;
import java.util.Map;

public class sample_1335 {

    public static boolean process_tree(Object node) {
        if (node instanceof List) {
            List<?> list = (List<?>) node;
            for (Object item : list) {
                if (process_tree(item)) {
                    return true;
                }
            }
            return false;
        } else if (node instanceof Map) {
            Map<?, ?> map = (Map<?, ?>) node;
            for (Object value : map.values()) {
                if (process_tree(value)) {
                    return true;
                }
            }
            return false;
        } else {
            return "TERMINATE".equals(node);
        }
    }

    public static void main(String[] args) {
        List<Map<String, List<Map<String, String>>>> tree = List.of(Map.of("root", List.of(
            Map.of("child1", "TERMINATE"),
            Map.of("child2", "CONTINUE"),
            Map.of("child3", List.of(
                Map.of("subchild1", "TERMINATE"),
                Map.of("subchild2", "CONTINUE")
            ))
        )));
        if (process_tree(tree)) {
            System.out.println("Termination detected.");
        } else {
            System.out.println("No termination found.");
        }
    }
}