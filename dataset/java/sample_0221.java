import java.util.ArrayList;
import java.util.List;

public class sample_0221 {

    static class Node {
        int value;
        List<Node> children;

        Node(int value) {
            this.value = value;
            this.children = new ArrayList<>();
        }

        void addChild(Node child) {
            this.children.add(child);
        }
    }

    static class Tree {
        Node root;

        Tree(Node root) {
            this.root = root;
        }

        List<Object[]> traverse(Node node, int depth) {
            List<Object[]> result = new ArrayList<>();
            if (node != null) {
                result.add(new Object[]{node.value, depth});
                for (Node child : node.children) {
                    result.addAll(traverse(child, depth + 1));
                }
            }
            return result;
        }
    }

    static boolean checkBoundaryConditions(Tree tree) {
        List<Object[]> traversal = tree.traverse(tree.root, 0);
        int maxDepth = 0;
        for (Object[] entry : traversal) {
            maxDepth = Math.max(maxDepth, (int) entry[1]);
        }
        if (maxDepth > 10) {
            return false;
        }
        if (traversal.size() > 20) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        Node child1 = new Node(2);
        Node child2 = new Node(3);
        Node child3 = new Node(4);
        Node child4 = new Node(5);
        root.addChild(child1);
        root.addChild(child2);
        child1.addChild(child3);
        child1.addChild(child4);
        Tree tree = new Tree(root);
        if (checkBoundaryConditions(tree)) {
            System.out.println("Boundary conditions satisfied.");
        } else {
            System.out.println("Boundary conditions violated.");
        }
    }
}