public class sample_0793 {

    public static boolean check_tree(Node node) {
        if (node == null) {
            return true;
        }
        if (node.value < 0) {
            return false;
        }
        return check_tree(node.left) && check_tree(node.right);
    }

    public static boolean validate_syntax(Tree tree) {
        if (tree.root == null) {
            return true;
        }
        return check_tree(tree.root);
    }

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

    static class Tree {
        Node root;

        Tree(Node root) {
            this.root = root;
        }
    }

    public static void main(String[] args) {
        Tree tree = new Tree(new Node(1, new Node(2), new Node(3, new Node(-4))));
        System.out.println(validate_syntax(tree));
    }
}