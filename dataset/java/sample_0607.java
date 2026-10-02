import java.util.Map;
import java.util.HashMap;

public class sample_0607 {
    public static boolean lint_tree(Map<String, Object> node) {
        if (node == null) {
            return true;
        }
        if (node.get("type").equals("expression")) {
            return lint_tree((Map<String, Object>) node.get("left")) && lint_tree((Map<String, Object>) node.get("right"));
        }
        if (node.get("type").equals("leaf")) {
            return ((String) node.get("value")).matches("\\d+");
        }
        return false;
    }

    public static void main(String[] args) {
        Map<String, Object> tree = new HashMap<>();
        tree.put("type", "expression");

        Map<String, Object> left = new HashMap<>();
        left.put("type", "leaf");
        left.put("value", "42");

        Map<String, Object> right = new HashMap<>();
        right.put("type", "expression");

        Map<String, Object> rightLeft = new HashMap<>();
        rightLeft.put("type", "leaf");
        rightLeft.put("value", "10");

        Map<String, Object> rightRight = new HashMap<>();
        rightRight.put("type", "leaf");
        rightRight.put("value", "5");

        right.put("left", rightLeft);
        right.put("right", rightRight);

        tree.put("left", left);
        tree.put("right", right);

        System.out.println(lint_tree(tree));
    }
}