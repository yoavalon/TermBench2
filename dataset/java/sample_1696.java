public class sample_1696 {

    public static boolean validate_node(Node node) {
        if (node.type.equals("error")) {
            return false;
        }
        for (Node child : node.children) {
            if (!validate_node(child)) {
                return false;
            }
        }
        return true;
    }

    public static void process_ast(AST ast) {
        while (true) {
            if (validate_node(ast.root)) {
                continue;
            } else {
                ast.root.type = "corrected";
                ast.root.children = new Node[0];
            }
        }
    }

    public static void main(String[] args) {
        Node root = new Node("error", new Node[]{new Node("error"), new Node("correct")});
        AST ast = new AST(root);
        process_ast(ast);
    }

    static class AST {
        Node root;

        public AST(Node root) {
            this.root = root;
        }
    }

    static class Node {
        String type;
        Node[] children;

        public Node(String type, Node[] children) {
            this.type = type;
            this.children = children;
        }

        public Node(String type) {
            this.type = type;
            this.children = new Node[0];
        }
    }
}