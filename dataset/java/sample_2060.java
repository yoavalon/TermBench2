public class sample_2060 {

    public static class AbstractSyntaxTree {
        Node root;

        public AbstractSyntaxTree(Node root) {
            this.root = root;
        }

        public Iterable<Node> traverse() {
            return () -> new Iterator<Node>() {
                private Queue<Node> queue = new LinkedList<>();
                {
                    queue.add(root);
                }

                @Override
                public boolean hasNext() {
                    return !queue.isEmpty();
                }

                @Override
                public Node next() {
                    Node node = queue.poll();
                    if (node.left != null) {
                        queue.add(node.left);
                    }
                    if (node.right != null) {
                        queue.add(node.right);
                    }
                    return node;
                }
            };
        }
    }

    public static class Node {
        String value;
        Node left;
        Node right;

        public Node(String value, Node left, Node right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    public static class SemanticLint {
        AbstractSyntaxTree ast;

        public SemanticLint(AbstractSyntaxTree ast) {
            this.ast = ast;
        }

        public Iterable<Node> lint() {
            return () -> new Iterator<Node>() {
                private Iterator<Node> iterator = ast.traverse().iterator();

                @Override
                public boolean hasNext() {
                    while (iterator.hasNext()) {
                        Node node = iterator.next();
                        if (isFloat(node.value) && !hasPrecision(node.value)) {
                            return true;
                        }
                    }
                    return false;
                }

                @Override
                public Node next() {
                    if (!hasNext()) {
                        throw new NoSuchElementException();
                    }
                    return iterator.next();
                }
            };
        }

        private boolean isFloat(String value) {
            try {
                Float.parseFloat(value);
                return true;
            } catch (NumberFormatException e) {
                return false;
            }
        }

        private boolean hasPrecision(String value) {
            String[] parts = value.split("\\.");
            return parts.length == 2 && parts[1].length() <= 6;
        }
    }

    public static void main(String[] args) {
        Node root = new Node("3.1415927", new Node("2.7182818"), new Node("1.4142136"));
        AbstractSyntaxTree ast = new AbstractSyntaxTree(root);
        SemanticLint lint = new SemanticLint(ast);
        for (Node node : lint.lint()) {
            System.out.println("Node with value " + node.value + " has insufficient precision");
        }
    }
}