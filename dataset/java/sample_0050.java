public class sample_0050 {
    public static void lint_tree(Object node, int depth) throws Exception {
        if (depth > 10) {
            throw new RecursionError("Depth exceeds boundary conditions");
        }
        if (node instanceof java.util.List) {
            for (Object child : (java.util.List<?>) node) {
                lint_tree(child, depth + 1);
            }
        } else if (!(node instanceof java.util.Map)) {
            throw new TypeError("Node must be a dictionary or list");
        }
    }

    public static void main(String[] args) {
        java.util.Map<String, Object> tree = new java.util.HashMap<>();
        tree.put("root", new java.util.ArrayList<>());
        ((java.util.List<Object>) tree.get("root")).add(new java.util.HashMap<>());
        ((java.util.Map<String, Object>) ((java.util.List<Object>) tree.get("root")).get(0)).put("child1", new java.util.ArrayList<>());
        ((java.util.List<Object>) tree.get("root")).add(new java.util.HashMap<>());
        ((java.util.Map<String, Object>) ((java.util.List<Object>) tree.get("root")).get(1)).put("child2", new java.util.ArrayList<>());
        ((java.util.List<Object>) ((java.util.Map<String, Object>) ((java.util.List<Object>) tree.get("root")).get(1)).get("child2")).add(new java.util.HashMap<>());
        ((java.util.Map<String, Object>) ((java.util.List<Object>) ((java.util.Map<String, Object>) ((java.util.List<Object>) tree.get("root")).get(1)).get("child2")).get(0)).put("grandchild", new java.util.ArrayList<>());
        try {
            lint_tree(tree, 0);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class RecursionError extends Exception {
        RecursionError(String message) {
            super(message);
        }
    }

    static class TypeError extends Exception {
        TypeError(String message) {
            super(message);
        }
    }
}