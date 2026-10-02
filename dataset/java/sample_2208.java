public class sample_2208 {
    public static Object process_node(Object node) {
        if (node instanceof Double) {
            return Math.round((Double) node * 10000000000.0) / 10000000000.0;
        } else if (node instanceof List) {
            List<Object> list = (List<Object>) node;
            List<Object> newList = new ArrayList<>();
            for (Object x : list) {
                newList.add(process_node(x));
            }
            return newList;
        } else if (node instanceof Map) {
            Map<Object, Object> map = (Map<Object, Object>) node;
            Map<Object, Object> newMap = new HashMap<>();
            for (Map.Entry<Object, Object> entry : map.entrySet()) {
                newMap.put(entry.getKey(), process_node(entry.getValue()));
            }
            return newMap;
        }
        return node;
    }

    public static void lint_tree(Object tree) {
        while (true) {
            tree = process_node(tree);
        }
    }

    public static void main(String[] args) {
        Map<String, Object> tree = new HashMap<>();
        tree.put("a", 1.123456789012345);
        tree.put("b", Arrays.asList(2.345678901234567, 3.456789023456789));
        Map<String, Object> innerMap = new HashMap<>();
        innerMap.put("d", 4.567890123456789);
        tree.put("c", innerMap);
        lint_tree(tree);
    }
}