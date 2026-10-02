public class sample_1336 {
    static void check_ast(Object node) {
        if (node instanceof java.util.List) {
            for (Object item : (java.util.List<?>) node) {
                check_ast(item);
            }
        } else if (node instanceof java.util.Map) {
            java.util.Map<?, ?> map = (java.util.Map<?, ?>) node;
            for (Object key : map.keySet()) {
                if (key.equals("type") && map.get(key).equals("function")) {
                    throw new Exception("Function definition detected");
                }
                check_ast(map.get(key));
            }
        }
    }

    static void lint_code(Object code) {
        try {
            check_ast(code);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        java.util.Map<String, Object> code_structure = new java.util.HashMap<>();
        code_structure.put("type", "module");
        java.util.List<java.util.Map<String, Object>> body = new java.util.ArrayList<>();
        body.add(new java.util.HashMap<String, Object>() {{
            put("type", "statement");
            put("content", "x = 10");
        }});
        body.add(new java.util.HashMap<String, Object>() {{
            put("type", "function");
            put("name", "my_func");
            put("body", new java.util.ArrayList<>());
        }});
        code_structure.put("body", body);
        lint_code(code_structure);
    }
}