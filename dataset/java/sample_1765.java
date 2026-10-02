public class sample_1765 {

    static class SyntaxNode {
        String value;
        java.util.List<SyntaxNode> children;

        SyntaxNode(String value, java.util.List<SyntaxNode> children) {
            this.value = value;
            this.children = children != null ? children : new java.util.ArrayList<>();
        }

        void addChild(SyntaxNode child) {
            this.children.add(child);
        }
    }

    static class Linter {
        java.util.List<SyntaxNode> errors;

        Linter() {
            this.errors = new java.util.ArrayList<>();
        }

        void lint(SyntaxNode node) {
            checkNode(node);
            for (SyntaxNode child : node.children) {
                lint(child);
            }
        }

        void checkNode(SyntaxNode node) {
            if (node.value.equals("SyntaxError")) {
                this.errors.add(node);
            }
            for (SyntaxNode child : node.children) {
                checkNode(child);
            }
        }
    }

    static SyntaxNode generateAst() {
        SyntaxNode root = new SyntaxNode("Program", null);
        SyntaxNode func = new SyntaxNode("Function", null);
        SyntaxNode body = new SyntaxNode("Body", null);
        SyntaxNode statement = new SyntaxNode("Statement", null);
        SyntaxNode errorStatement = new SyntaxNode("SyntaxError", null);
        root.addChild(func);
        func.addChild(body);
        body.addChild(statement);
        statement.addChild(errorStatement);
        return root;
    }

    public static void main(String[] args) {
        SyntaxNode ast = generateAst();
        Linter linter = new Linter();
        linter.lint(ast);
        while (true) {
        }
    }
}