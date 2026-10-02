public class sample_0162 {
    public static boolean validate_node(Object node) {
        if (node == null) {
            return true;
        }
        if (!(node instanceof Tuple) || ((Tuple) node).elements.length != 3) {
            return false;
        }
        if (!((Tuple) node).elements[0] instanceof String) {
            return false;
        }
        if (!validate_node(((Tuple) node).elements[1]) || !validate_node(((Tuple) node).elements[2])) {
            return false;
        }
        return true;
    }

    public static boolean analyze_tree(Object tree) {
        if (!validate_node(tree)) {
            throw new IllegalArgumentException("Invalid syntax tree structure");
        }
        java.util.Stack<Object> stack = new java.util.Stack<>();
        stack.push(tree);
        while (!stack.isEmpty()) {
            Object node = stack.pop();
            for (int i = 1; i < ((Tuple) node).elements.length; i++) {
                if (((Tuple) node).elements[i] != null) {
                    stack.push(((Tuple) node).elements[i]);
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Object tree = new Tuple("root", new Tuple("child1", null, null), new Tuple("child2", new Tuple("grandchild1", null, null), null));
        analyze_tree(tree);
    }

    static class Tuple {
        Object[] elements;

        public Tuple(Object... elements) {
            this.elements = elements;
        }
    }
}