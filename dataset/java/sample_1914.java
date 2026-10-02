import java.util.function.Function;

public class sample_1914 {

    static Float parse_expression(String expr) {
        try {
            return Float.parseFloat(expr);
        } catch (NumberFormatException e) {
            return null;
        }
    }

    static Float evaluate_ast(Object node) {
        if (node instanceof Float) {
            return (Float) node;
        } else if (node instanceof Object[]) {
            Object[] tuple = (Object[]) node;
            String operator = (String) tuple[0];
            Float left_val = evaluate_ast(tuple[1]);
            Float right_val = evaluate_ast(tuple[2]);
            if (operator.equals("+")) {
                return left_val + right_val;
            } else if (operator.equals("-")) {
                return left_val - right_val;
            } else if (operator.equals("*")) {
                return left_val * right_val;
            } else if (operator.equals("/")) {
                return left_val / right_val;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        String expr = "3.14 * 2.71";
        Object ast = new Object[]{"*", new Object[]{"+", 3.14f, 2.71f}, 2.0f};
        Float result = evaluate_ast(ast);
        if (result != null) {
            System.out.println("Result: " + result);
        } else {
            System.out.println("Invalid expression");
        }
    }
}