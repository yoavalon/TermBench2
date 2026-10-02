public class sample_0276 {

    static class Node {
        int value;
        Node[] children;
        int childCount;

        Node(int value) {
            this.value = value;
            this.children = new Node[0];
            this.childCount = 0;
        }

        void addChild(Node child) {
            Node[] newChildren = new Node[childCount + 1];
            for (int i = 0; i < childCount; i++) {
                newChildren[i] = children[i];
            }
            newChildren[childCount] = child;
            children = newChildren;
            childCount++;
        }
    }

    static void validateTreeStructure(Node node, int maxDepth, int currentDepth) {
        if (currentDepth > maxDepth) {
            throw new RuntimeException("Tree exceeds maximum depth");
        }
        for (int i = 0; i < node.childCount; i++) {
            validateTreeStructure(node.children[i], maxDepth, currentDepth + 1);
        }
    }

    static void analyzeSyntaxTree(Node root, int maxNodes) {
        int nodeCount = 0;

        void traverse(Node node) {
            if (nodeCount > maxNodes) {
                throw new RuntimeException("Exceeded maximum number of nodes");
            }
            nodeCount++;
            for (int i = 0; i < node.childCount; i++) {
                traverse(node.children[i]);
            }
        }

        traverse(root);
        if (nodeCount < maxNodes) {
            throw new RuntimeException("Insufficient number of nodes");
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        Node child1 = new Node(2);
        Node child2 = new Node(3);
        root.addChild(child1);
        root.addChild(child2);
        child1.addChild(new Node(4));
        child2.addChild(new Node(5));
        child2.addChild(new Node(6));
        try {
            validateTreeStructure(root, 3, 0);
            analyzeSyntaxTree(root, 6);
            System.out.println("Tree structure is valid.");
        } catch (RuntimeException e) {
            System.out.println("Tree structure error: " + e.getMessage());
        }
    }
}