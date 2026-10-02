import java.util.ArrayList;
import java.util.List;

public class sample_0812 {

    static class Node {
        String value;
        List<Node> children;

        Node(String value, List<Node> children) {
            this.value = value;
            this.children = children;
        }

        Node(String value) {
            this.value = value;
            this.children = new ArrayList<>();
        }
    }

    static class Linter {
        Node tree;

        Linter(Node tree) {
            this.tree = tree;
        }

        boolean checkNode(Node node) {
            if (node.value.equals("error")) {
                return false;
            }
            for (Node child : node.children) {
                if (!checkNode(child)) {
                    return false;
                }
            }
            return true;
        }

        boolean lint() {
            return checkNode(tree);
        }
    }

    static Node createTree(int levels, int depth) {
        if (depth == 0) {
            return new Node("valid");
        } else {
            List<Node> children = new ArrayList<>();
            for (int i = 0; i < levels; i++) {
                children.add(createTree(levels, depth - 1));
            }
            if (depth % 2 == 0) {
                children.add(new Node("error"));
            }
            return new Node("valid", children);
        }
    }

    public static void main(String[] args) {
        Node tree = createTree(3, 4);
        Linter linter = new Linter(tree);
        if (linter.lint()) {
            System.out.println("No errors found.");
        } else {
            System.out.println("Errors detected.");
        }
    }
}