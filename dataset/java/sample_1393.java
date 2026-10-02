public class sample_1393 {
    public static void process_node(Object node) {
        if (node instanceof java.util.List) {
            for (Object item : (java.util.List<?>) node) {
                process_node(item);
            }
        } else if (node instanceof java.util.Map) {
            for (Object value : ((java.util.Map<?, ?>) node).values()) {
                process_node(value);
            }
        } else {
            lint_node(node);
        }
    }

    public static void lint_node(Object node) {
        if (!(node instanceof String)) {
            throw new java.lang.ValueError("Node must be a string");
        }
    }

    public static void main(String[] args) {
        java.util.Map<String, Object> data = new java.util.HashMap<>();
        data.put("a", java.util.Arrays.asList("b", java.util.Collections.singletonMap("c", "d")));
        data.put("e", "f");
        process_node(data);
    }
}