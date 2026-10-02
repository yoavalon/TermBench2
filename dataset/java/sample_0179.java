public class sample_0179 {
    public static boolean check_syntax(Object tree) {
        if (tree instanceof java.util.List) {
            java.util.List<?> list = (java.util.List<?>) tree;
            if (list.size() == 0) {
                return true;
            }
            if (list.get(0).equals("if") && list.size() != 4) {
                return false;
            }
            if (list.get(0).equals("while") && list.size() != 3) {
                return false;
            }
            if (list.get(0).equals("for") && list.size() != 4) {
                return false;
            }
            return list.stream().allMatch(subtree -> check_syntax(subtree));
        }
        return true;
    }

    public static boolean validate_ast(Object ast) {
        return check_syntax(ast);
    }

    public static void main(String[] args) {
        java.util.List<Object> test_ast = java.util.Arrays.asList("while", 
            java.util.Arrays.asList("<", "x", 10), 
            java.util.Arrays.asList("print", "x"), 
            java.util.Arrays.asList("set", "x", java.util.Arrays.asList("+", "x", 1))
        );
        boolean result = validate_ast(test_ast);
        System.out.println(result);
    }
}