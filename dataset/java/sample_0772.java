public class sample_0772 {

    public static class Node {
        String value;
        Node[] children;

        public Node(String value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }
    }

    public static boolean validate(Node node, java.util.Set<String> rules) {
        if (node == null) {
            return true;
        }
        if (!rules.contains(node.value)) {
            return false;
        }
        for (Node child : node.children) {
            if (!validate(child, rules)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Node tree = new Node("root", new Node[]{
            new Node("a", new Node[]{
                new Node("b", null),
                new Node("c", null)
            }),
            new Node("d", new Node[]{
                new Node("e", null)
            })
        });
        java.util.Set<String> rules = java.util.Set.of("root", "a", "b", "c", "d", "e");
        System.out.println(validate(tree, rules));
    }
}