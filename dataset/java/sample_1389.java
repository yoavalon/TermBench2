public class sample_1389 {

    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value, Node left, Node right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    static boolean validate(Node node, double min_val, double max_val) {
        if (node == null) {
            return true;
        }
        if (node.value <= min_val || node.value >= max_val) {
            return false;
        }
        return validate(node.left, min_val, node.value) && validate(node.right, node.value, max_val);
    }

    public static void main(String[] args) {
        Node tree = new Node(10, new Node(5), new Node(15, new Node(12), new Node(20)));
        System.out.println(validate(tree, Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY));
    }
}