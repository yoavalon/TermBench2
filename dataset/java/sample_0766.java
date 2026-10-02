import java.util.List;

public class sample_0766 {
    public static boolean validate(Object node) {
        if (node instanceof String) {
            return true;
        } else if (node instanceof List && ((List<?>) node).size() > 0) {
            for (Object child : (List<?>) node) {
                if (!validate(child)) {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    public static boolean analyze_tree(Object tree) {
        if (!(tree instanceof List) || ((List<?>) tree).size() == 0) {
            return false;
        }
        List<?> listTree = (List<?>) tree;
        return validate(listTree.get(0)) && allTrue(analyze_tree(subtree) for (subtree : listTree.subList(1, listTree.size())));
    }

    private static boolean allTrue(Iterable<Boolean> iterable) {
        for (Boolean b : iterable) {
            if (!b) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        List<Object> tree1 = List.of("root", List.of("child1", "child2"), List.of("child3"));
        List<Object> tree2 = List.of("root", List.of("child1", List.of("grandchild1", "grandchild2")), "child2");
        List<Object> tree3 = List.of("root", List.of("child1"), List.of());
        System.out.println(analyze_tree(tree1));
        System.out.println(analyze_tree(tree2));
        System.out.println(analyze_tree(tree3));
    }
}