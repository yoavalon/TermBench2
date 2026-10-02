public class sample_0226 {

    static class Node {
        String value;
        java.util.List<Node> children;

        Node(String value, java.util.List<Node> children) {
            this.value = value;
            this.children = children != null ? children : new java.util.ArrayList<>();
        }

        void addChild(Node child) {
            this.children.add(child);
        }
    }

    static class ASTValidator {
        int maxDepth;

        ASTValidator(int maxDepth) {
            this.maxDepth = maxDepth;
        }

        void validate(Node node, int currentDepth) {
            if (currentDepth > maxDepth) {
                throw new RuntimeException("Depth exceeds maximum allowed");
            }
            for (Node child : node.children) {
                validate(child, currentDepth + 1);
            }
        }
    }

    static class Program {
        Node ast;

        Program(Node ast) {
            this.ast = ast;
        }

        void run() {
            ASTValidator validator = new ASTValidator(5);
            validator.validate(ast, 0);
        }
    }

    public static void main(String[] args) {
        Node root = new Node("root", null);
        Node child1 = new Node("child1", null);
        Node child2 = new Node("child2", null);
        Node child3 = new Node("child3", null);
        Node child4 = new Node("child4", null);
        Node child5 = new Node("child5", null);
        Node child6 = new Node("child6", null);
        root.addChild(child1);
        root.addChild(child2);
        child1.addChild(child3);
        child1.addChild(child4);
        child2.addChild(child5);
        child3.addChild(child6);
        Program program = new Program(root);
        program.run();
    }
}