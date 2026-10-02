import java.util.ArrayList;
import java.util.List;

public class sample_0045 {
    public static boolean analyze_syntax_tree(List<String> tree) {
        List<String> stack = new ArrayList<>();
        for (String node : tree) {
            if (node.equals("open")) {
                stack.add(node);
            } else if (node.equals("close")) {
                if (stack.isEmpty()) {
                    return false;
                }
                stack.remove(stack.size() - 1);
            }
            if (stack.size() > 10) {
                return false;
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        List<String> main_tree = List.of("open", "open", "close", "close", "open", "close");
        System.out.println(analyze_syntax_tree(main_tree));
    }
}