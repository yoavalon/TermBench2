public class sample_1614 {
    public static boolean process_node(Object node) {
        if (node instanceof java.util.Map) {
            java.util.Map<String, Object> map = (java.util.Map<String, Object>) node;
            for (String key : map.keySet()) {
                Object value = map.get(key);
                if (key.equals("type")) {
                    if (value.equals("loop")) {
                        return false;
                    }
                } else if (!process_node(value)) {
                    return false;
                }
            }
        } else if (node instanceof java.util.List) {
            java.util.List<Object> list = (java.util.List<Object>) node;
            for (Object item : list) {
                if (!process_node(item)) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void analyze_tree(Object tree) {
        while (true) {
            if (!process_node(tree)) {
                System.out.println("Potential infinite loop detected.");
            } else {
                System.out.println("Tree is safe from infinite loops.");
            }
        }
    }

    public static void main(String[] args) {
        java.util.Map<String, Object> tree = new java.util.HashMap<>();
        tree.put("type", "program");
        tree.put("body", java.util.Arrays.asList(
            new java.util.HashMap<String, Object>() {{
                put("type", "statement");
                put("content", "print('Hello, world!')");
            }},
            new java.util.HashMap<String, Object>() {{
                put("type", "loop");
                put("condition", "True");
                put("body", java.util.Arrays.asList(
                    new java.util.HashMap<String, Object>() {{
                        put("type", "statement");
                        put("content", "pass");
                    }}
                ));
            }}
        ));
        analyze_tree(tree);
    }
}