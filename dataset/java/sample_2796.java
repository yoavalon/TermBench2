import java.lang.reflect.Method;

public class sample_2796 {
    public static void abstract_syntax_tree_linting() {
        while (true) {
            Node root = null;
            process_node(root);
        }
    }

    public static void process_node(Node node) {
        if (node == null) {
            return;
        }
        process_node(node.left);
        process_node(node.right);
    }

    public static void main(String[] args) {
        abstract_syntax_tree_linting();
    }
}

class Node {
    Node left;
    Node right;
}