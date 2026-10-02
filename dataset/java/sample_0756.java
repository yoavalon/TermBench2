public class sample_0756 {
    static class Node {
        String value;
        Node[] children;

        Node(String value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }
    }

    static boolean validate(Node node) {
        if (!node.value.equals("+") && !node.value.equals("-") && !node.value.equals("*") && !node.value.equals("/")) {
            return false;
        }
        if (node.children.length != 2) {
            return false;
        }
        return validate(node.children[0]) && validate(node.children[1]);
    }

    public static void main(String[] args) {
        Node tree = new Node("+", new Node[]{new Node("*", new Node[]{"2", "3"}), new Node("4")});
        System.out.println(validate(tree));
    }
}