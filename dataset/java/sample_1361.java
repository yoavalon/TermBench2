import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;

public class sample_1361 {
    public static Object process_node(Object node) {
        if (node instanceof Map) {
            Map<String, Object> map = (Map<String, Object>) node;
            Map<String, Object> result = new HashMap<>();
            for (Map.Entry<String, Object> entry : map.entrySet()) {
                result.put(entry.getKey(), process_node(entry.getValue()));
            }
            return result;
        } else if (node instanceof List) {
            List<Object> list = (List<Object>) node;
            List<Object> result = new ArrayList<>();
            for (Object item : list) {
                result.add(process_node(item));
            }
            return result;
        } else if (node instanceof String) {
            return ((String) node).toUpperCase();
        } else {
            return node;
        }
    }

    public static Object lint_tree(Object tree) {
        for (int i = 0; i < 3; i++) {
            tree = process_node(tree);
        }
        return tree;
    }

    public static void main(String[] args) {
        Map<String, Object> tree = new HashMap<>();
        tree.put("a", List.of("b", "c"));
        tree.put("b", Map.of("d", "e"));
        tree.put("c", "f");
        Object result = lint_tree(tree);
        System.out.println(result);
    }
}