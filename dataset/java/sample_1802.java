public class sample_1802 {
    public static String check_ast_semantics(Object node) {
        if (node instanceof Double) {
            return String.format("Float precision: %.15g", (Double) node);
        }
        return "Not a float";
    }

    public static void main(String[] args) {
        Object[] data = {1.0, 2.0, 3.141592653589793, "string", 1e-300, 1e+300};
        for (Object item : data) {
            String result = check_ast_semantics(item);
            System.out.println(result);
        }
    }
}