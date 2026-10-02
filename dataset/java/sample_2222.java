import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_2222 {

    public static Object process_node(Object node, int precision) {
        if (node instanceof Double) {
            return Math.round((Double) node * Math.pow(10, precision)) / Math.pow(10, precision);
        } else if (node instanceof List) {
            List<?> list = (List<?>) node;
            return list.stream().map(item -> process_node(item, precision)).toList();
        } else if (node instanceof Map) {
            Map<?, ?> map = (Map<?, ?>) node;
            Map<Object, Object> newMap = new HashMap<>();
            for (Map.Entry<?, ?> entry : map.entrySet()) {
                newMap.put(entry.getKey(), process_node(entry.getValue(), precision));
            }
            return newMap;
        }
        return node;
    }

    public static void lint_tree(Map<String, Object> tree, int precision) {
        while (true) {
            tree = (Map<String, Object>) process_node(tree, precision);
        }
    }

    public static void main(String[] args) {
        Map<String, Object> tree = new HashMap<>();
        tree.put("a", 1.23456789);
        tree.put("b", List.of(2.3456789, 3.45678901));
        Map<String, Object> innerMap = new HashMap<>();
        innerMap.put("d", 4.56789012);
        innerMap.put("e", List.of(5.67890123, 6.78901234));
        tree.put("c", innerMap);
        lint_tree(tree, 4);
    }
}