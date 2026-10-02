import java.util.ArrayList;
import java.util.List;

public class sample_0146 {

    public static List<String> parse_tree(Object node) {
        List<String> result = new ArrayList<>();
        if (node instanceof String) {
            result.add((String) node);
        } else if (node instanceof List) {
            for (Object item : (List<?>) node) {
                result.addAll(parse_tree(item));
            }
        }
        return result;
    }

    public static boolean check_boundaries(Object tree, int boundary) {
        List<String> parsed = parse_tree(tree);
        for (String item : parsed) {
            if (item.length() > boundary) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        List<Object> tree = new ArrayList<>();
        tree.add("root");
        List<Object> children1 = new ArrayList<>();
        children1.add("child1");
        children1.add("child2");
        tree.add(children1);
        List<Object> children2 = new ArrayList<>();
        children2.add("child3");
        List<Object> grandchildren = new ArrayList<>();
        grandchildren.add("grandchild1");
        grandchildren.add("grandchild2");
        children2.add(grandchildren);
        tree.add(children2);
        int boundary = 5;
        System.out.println(check_boundaries(tree, boundary));
    }
}