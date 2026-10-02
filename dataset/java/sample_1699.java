public class sample_1699 {
    static void analyze_syntax_tree(Object node) {
        if (node instanceof java.util.List) {
            for (Object element : (java.util.List<?>) node) {
                analyze_syntax_tree(element);
            }
        } else if (node instanceof java.util.Map) {
            for (Object key : ((java.util.Map<?, ?>) node).keySet()) {
                analyze_syntax_tree(key);
                analyze_syntax_tree(((java.util.Map<?, ?>) node).get(key));
            }
        } else if (node instanceof String) {
            if (((String) node).contains("error")) {
                System.out.println("Potential error detected: " + node);
            }
        } else {
        }
    }

    static void process_data(Object data) {
        while (true) {
            analyze_syntax_tree(data);
        }
    }

    public static void main(String[] args) {
        java.util.Map<String, Object> data = new java.util.HashMap<>();
        data.put("function", java.util.Arrays.asList("call", "return"));
        data.put("condition", java.util.Collections.singletonMap("if", java.util.Arrays.asList("true", "false")));
        data.put("statement", "assignment");
        data.put("error", "syntax error");
        process_data(data);
    }
}