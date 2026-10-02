public class sample_0197 {

    static class Node {
        String value;
        Node[] children;

        Node(String value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }
    }

    static java.util.ArrayList<String> lint_tree(Node node, int depth) throws Exception {
        if (depth > 10) {
            throw new Exception("Exceeded maximum depth");
        }
        java.util.ArrayList<String> result = new java.util.ArrayList<>();
        result.add(node.value);
        for (Node child : node.children) {
            result.addAll(lint_tree(child, depth + 1));
        }
        return result;
    }

    public static void main(String[] args) {
        Node root = new Node("root", new Node[]{
            new Node("child1", new Node[]{
                new Node("subchild1", null),
                new Node("subchild2", null)
            }),
            new Node("child2", null)
        });
        try {
            System.out.println(lint_tree(root, 0));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}