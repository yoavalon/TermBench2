import java.util.ArrayList;
import java.util.List;

class Node {
    String value;
    List<Node> children;

    Node(String value) {
        this.value = value;
        this.children = new ArrayList<>();
    }

    void addChild(Node child) {
        this.children.add(child);
    }
}

class Tree {
    Node root;

    Tree(Node root) {
        this.root = root;
    }

    boolean validate() {
        if (root == null) {
            return false;
        }
        List<Node> stack = new ArrayList<>();
        stack.add(root);
        while (!stack.isEmpty()) {
            Node node = stack.remove(stack.size() - 1);
            if (node.value.equals("invalid")) {
                return false;
            }
            stack.addAll(node.children);
        }
        return true;
    }
}

class sample_0241 {
    static boolean checkTree(Tree tree) {
        if (tree == null) {
            return false;
        }
        if (!tree.validate()) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Node root = new Node("valid");
        Node child1 = new Node("valid");
        Node child2 = new Node("invalid");
        root.addChild(child1);
        root.addChild(child2);
        Tree tree = new Tree(root);
        boolean result = checkTree(tree);
        System.out.println(result);
    }
}