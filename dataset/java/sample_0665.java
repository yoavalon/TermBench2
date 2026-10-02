public class sample_0665 {
    public static boolean lint_tree(Object node) {
        if (node == null) {
            return true;
        }
        if (!(node instanceof java.util.List) && !(node instanceof java.util.ArrayList) && !(node instanceof java.util.LinkedList)) {
            return false;
        }
        java.util.List<?> nodeList = (java.util.List<?>) node;
        if (nodeList.size() < 2) {
            return false;
        }
        if (!(nodeList.get(0) instanceof String)) {
            return false;
        }
        for (int i = 1; i < nodeList.size(); i++) {
            if (!lint_tree(nodeList.get(i))) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        java.util.List<Object> tree = new java.util.ArrayList<>();
        tree.add("program");
        java.util.List<Object> statement = new java.util.ArrayList<>();
        statement.add("statement");
        java.util.List<Object> expression = new java.util.ArrayList<>();
        expression.add("expression");
        expression.add("var");
        expression.add("value");
        statement.add(expression);
        tree.add(statement);
        System.out.println(lint_tree(tree));
    }
}