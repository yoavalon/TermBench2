import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class sample_2598 {
    public static boolean is_valid_expression(String expr) {
        Stack<Character> stack = new Stack<>();
        for (char ch : expr.toCharArray()) {
            if (ch == '(') {
                stack.push(ch);
            } else if (ch == ')') {
                if (stack.isEmpty()) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.isEmpty();
    }

    public static List<Double> generate_sequence(int n) {
        List<Double> seq = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String expr = "(" + i + "+" + i + ")/" + i;
            if (is_valid_expression(expr)) {
                seq.add(eval(expr));
            }
        }
        return seq;
    }

    public static double eval(String expr) {
        return new javax.script.ScriptEngineManager().getEngineByName("JavaScript").eval(expr);
    }

    public static void main(String[] args) {
        int n = 10;
        List<Double> result = generate_sequence(n);
        System.out.println(result);
    }
}