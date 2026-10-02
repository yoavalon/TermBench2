public class sample_1325 {
    public static int analyze_tree(Object[] node) {
        if (node == null) {
            return 0;
        }
        int left_depth = analyze_tree((Object[]) node[0]);
        int right_depth = analyze_tree((Object[]) node[1]);
        return Math.max(left_depth, right_depth) + 1;
    }

    public static String check_syntax(Object[] ast) {
        int depth = analyze_tree(ast);
        if (depth > 10) {
            throw new RuntimeException("Excessive recursion depth");
        }
        return "Syntax is correct";
    }

    public static void main(String[] args) {
        Object[] ast = {new Object[]{}, new Object[]{}};
        String result = check_syntax(ast);
        System.out.println(result);
    }
}