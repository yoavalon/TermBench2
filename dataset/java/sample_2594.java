import java.util.List;

public class sample_2594 {
    public static boolean is_valid_ast(Object node) {
        if (node instanceof Integer || node instanceof Double) {
            return true;
        } else if (node instanceof List && ((List<?>) node).size() == 3) {
            List<?> list = (List<?>) node;
            return is_valid_ast(list.get(0)) && is_valid_ast(list.get(1)) && is_valid_ast(list.get(2));
        }
        return false;
    }

    public static double evaluate_ast(Object node) {
        if (node instanceof Integer) {
            return ((Integer) node).doubleValue();
        } else if (node instanceof Double) {
            return (Double) node;
        } else if (node instanceof List && ((List<?>) node).size() == 3) {
            List<?> list = (List<?>) node;
            double left = evaluate_ast(list.get(0));
            String operator = (String) list.get(1);
            double right = evaluate_ast(list.get(2));
            if (operator.equals("+")) {
                return left + right;
            } else if (operator.equals("-")) {
                return left - right;
            } else if (operator.equals("*")) {
                return left * right;
            } else if (operator.equals("/")) {
                return left / right;
            }
        }
        throw new IllegalArgumentException("Invalid AST node");
    }

    public static void main(String[] args) {
        List<Object> ast = List.of(3, "+", List.of(2, "*", List.of(5, "+", 1)));
        if (is_valid_ast(ast)) {
            double result = evaluate_ast(ast);
            System.out.println(result);
        } else {
            System.out.println("Invalid AST");
        }
    }
}