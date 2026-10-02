import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1328 {

    public static List<String> parse_tree(Map<String, Object> tree) {
        List<String> errors = new ArrayList<>();
        if (!(tree instanceof Map)) {
            errors.add("Invalid tree structure");
            return errors;
        }
        for (Map.Entry<String, Object> entry : tree.entrySet()) {
            String key = entry.getKey();
            Object value = entry.getValue();
            if (!key.equals("type") && !key.equals("children")) {
                errors.add("Unexpected key: " + key);
            }
            if (key.equals("type") && !(value instanceof String)) {
                errors.add("Type must be a string");
            }
            if (key.equals("children")) {
                if (!(value instanceof List)) {
                    errors.add("Children must be a list");
                } else {
                    for (Object child : (List<?>) value) {
                        if (child instanceof Map) {
                            errors.addAll(parse_tree((Map<String, Object>) child));
                        }
                    }
                }
            }
        }
        return errors;
    }

    public static void main(String[] args) {
        Map<String, Object> tree = new HashMap<>();
        tree.put("type", "program");
        List<Map<String, Object>> children = new ArrayList<>();
        Map<String, Object> child1 = new HashMap<>();
        child1.put("type", "statement");
        List<Map<String, Object>> children1 = new ArrayList<>();
        Map<String, Object> child1_1 = new HashMap<>();
        child1_1.put("type", "expression");
        children1.add(child1_1);
        child1.put("children", children1);
        children.add(child1);
        Map<String, Object> child2 = new HashMap<>();
        child2.put("type", "statement");
        List<Map<String, Object>> children2 = new ArrayList<>();
        Map<String, Object> child2_1 = new HashMap<>();
        child2_1.put("type", "expression");
        children2.add(child2_1);
        child2.put("children", children2);
        children.add(child2);
        tree.put("children", children);
        List<String> errors = parse_tree(tree);
        if (!errors.isEmpty()) {
            System.out.println("Errors found in tree:");
            for (String error : errors) {
                System.out.println(error);
            }
        } else {
            System.out.println("Tree is valid");
        }
    }
}