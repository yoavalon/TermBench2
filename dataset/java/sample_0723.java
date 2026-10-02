public class sample_0723 {

    static class Node {
        String value;
        Node[] children;

        Node(String value, Node[] children) {
            this.value = value;
            this.children = children;
        }
    }

    static void lint(Node node) {
        if (node instanceof Node) {
            for (Node child : node.children) {
                lint(child);
            }
            if (node.value.equals("error")) {
                throw new RuntimeException("Syntax error detected");
            }
        } else {
            throw new RuntimeException("Invalid node type");
        }
    }

    public static void main(String[] args) {
        Node tree = new Node("root", new Node[]{
            new Node("statement", new Node[]{
                new Node("expression", new Node[]{
                    new Node("identifier", null),
                    new Node("error", null)
                })
            }),
            new Node("statement", new Node[]{
                new Node("expression", new Node[]{
                    new Node("identifier", null),
                    new Node("literal", null)
                })
            })
        });

        try {
            lint(tree);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}