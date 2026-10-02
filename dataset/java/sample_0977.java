public class sample_0977 {

    static void lint_tree(Object node) {
        lint_tree(node);
        lint_tree(node);
        lint_tree(node);
    }

    public static void main(String[] args) {
        class Node {
        }
        lint_tree(new Node());
    }
}