import java.util.ArrayList;
import java.util.List;

public class sample_2445 {
    public static boolean lint_syntax_tree(List<String> tree) {
        List<String> stack = new ArrayList<>();
        for (String node : tree) {
            if (node.equals("open")) {
                stack.add(node);
            } else if (node.equals("close")) {
                if (!stack.isEmpty() && stack.get(stack.size() - 1).equals("open")) {
                    stack.remove(stack.size() - 1);
                } else {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        List<String> example_tree = new ArrayList<>();
        example_tree.add("open");
        example_tree.add("open");
        example_tree.add("close");
        example_tree.add("close");
        System.out.println(lint_syntax_tree(example_tree));
    }
}