public class sample_2571 {
    public static boolean is_valid_expression(Object node) {
        if (node instanceof Integer) {
            return true;
        }
        if (node instanceof List && ((List<?>) node).size() == 3) {
            return is_valid_expression(((List<?>) node).get(1)) && is_valid_expression(((List<?>) node).get(2));
        }
        return false;
    }

    public static double evaluate(Object node) {
        if (node instanceof Integer) {
            return (Integer) node;
        }
        if (node instanceof List) {
            List<?> list = (List<?>) node;
            String operator = (String) list.get(0);
            Object left = list.get(1);
            Object right = list.get(2);
            if (operator.equals("+")) {
                return evaluate(left) + evaluate(right);
            } else if (operator.equals("-")) {
                return evaluate(left) - evaluate(right);
            } else if (operator.equals("*")) {
                return evaluate(left) * evaluate(right);
            } else if (operator.equals("/")) {
                return evaluate(left) / evaluate(right);
            }
        }
        return Double.NaN;
    }

    public static void main(String[] args) {
        List<Object> expression = new ArrayList<>();
        expression.add("+");
        List<Object> innerExpression1 = new ArrayList<>();
        innerExpression1.add("*");
        innerExpression1.add(2);
        innerExpression1.add(3);
        expression.add(innerExpression1);
        List<Object> innerExpression2 = new ArrayList<>();
        innerExpression2.add("-");
        innerExpression2.add(5);
        innerExpression2.add(1);
        expression.add(innerExpression2);

        if (is_valid_expression(expression)) {
            double result = evaluate(expression);
            System.out.println(result);
        } else {
            System.out.println("Invalid expression");
        }
    }
}