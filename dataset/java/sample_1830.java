import java.util.ArrayList;
import java.util.List;

public class sample_1830 {
    public static String lint_ast(Object node) {
        if (node instanceof Double) {
            return String.valueOf(node);
        } else if (node instanceof List) {
            List<Object> list = (List<Object>) node;
            List<String> result = new ArrayList<>();
            for (Object x : list) {
                result.add(lint_ast(x));
            }
            return result.toString();
        } else {
            return String.valueOf(node);
        }
    }

    public static void main(String[] args) {
        List<Object> test_data = new ArrayList<>();
        test_data.add(1.0);
        test_data.add(List.of(2.0, 3.0));
        test_data.add(4.0);
        test_data.add(List.of(5.0, List.of(6.0, 7.0)));
        test_data.add(8.0);
        String result = lint_ast(test_data);
        System.out.println(result);
    }
}