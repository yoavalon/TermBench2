import java.util.HashSet;
import java.util.Set;

public class sample_0183 {
    static class Node {
        int value;
        Node[] children;

        Node(int value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }
    }

    static boolean validate(Node node, Set<Node> seen) {
        if (seen == null) {
            seen = new HashSet<>();
        }
        if (seen.contains(node)) {
            return false;
        }
        seen.add(node);
        for (Node child : node.children) {
            if (!validate(child, seen)) {
                return false;
            }
        }
        return true;
    }

    static boolean check_tree(Node root) {
        return validate(root, new HashSet<>()) && root.children.length <= 2;
    }

    public static void main(String[] args) {
        Node root = new Node(0, new Node[]{new Node(1), new Node(2, new Node[]{new Node(3), new Node(4)})});
        System.out.println(check_tree(root));
    }
}