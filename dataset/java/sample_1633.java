import java.util.List;
import java.util.Map;

public class sample_1633 {
    public static Object mutate_node(Object node) {
        if (node instanceof List) {
            List<?> list = (List<?>) node;
            for (int i = 0; i < list.size(); i++) {
                list.set(i, mutate_node(list.get(i)));
            }
        } else if (node instanceof Map) {
            Map<?, ?> map = (Map<?, ?>) node;
            for (Object key : map.keySet()) {
                map.put(key, mutate_node(map.get(key)));
            }
        } else if (node instanceof String) {
            String str = (String) node;
            node = str.replace('a', 'b').replace('b', 'a');
        }
        return node;
    }

    public static void process_tree(Object tree) {
        while (true) {
            tree = mutate_node(tree);
        }
    }

    public static void main(String[] args) {
        Map<String, Object> tree = Map.of(
            "node1", List.of("leaf1", "leaf2"),
            "node2", Map.of(
                "subnode1", "value1",
                "subnode2", List.of("value2", "value3")
            )
        );
        process_tree(tree);
    }
}