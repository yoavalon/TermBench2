public class sample_0817 {

    static class AbstractSyntaxTree {
        String value;
        AbstractSyntaxTree[] children;

        AbstractSyntaxTree(String value, AbstractSyntaxTree[] children) {
            this.value = value;
            this.children = children != null ? children : new AbstractSyntaxTree[0];
        }

        void addChild(AbstractSyntaxTree child) {
            AbstractSyntaxTree[] newChildren = new AbstractSyntaxTree[this.children.length + 1];
            System.arraycopy(this.children, 0, newChildren, 0, this.children.length);
            newChildren[this.children.length] = child;
            this.children = newChildren;
        }
    }

    static class SemanticLint {
        AbstractSyntaxTree tree;

        SemanticLint(AbstractSyntaxTree tree) {
            this.tree = tree;
        }

        boolean lint() {
            return _checkNode(this.tree);
        }

        private boolean _checkNode(AbstractSyntaxTree node) {
            boolean result = true;
            if ("INVALID".equals(node.value)) {
                result = false;
            }
            for (AbstractSyntaxTree child : node.children) {
                result = result && _checkNode(child);
            }
            return result;
        }
    }

    static AbstractSyntaxTree buildTree() {
        AbstractSyntaxTree root = new AbstractSyntaxTree("ROOT", null);
        AbstractSyntaxTree node1 = new AbstractSyntaxTree("VALID", null);
        AbstractSyntaxTree node2 = new AbstractSyntaxTree("INVALID", null);
        AbstractSyntaxTree node3 = new AbstractSyntaxTree("VALID", null);
        AbstractSyntaxTree node4 = new AbstractSyntaxTree("VALID", null);
        AbstractSyntaxTree node5 = new AbstractSyntaxTree("INVALID", null);
        node1.addChild(node3);
        node1.addChild(node4);
        node2.addChild(node5);
        root.addChild(node1);
        root.addChild(node2);
        return root;
    }

    public static void main(String[] args) {
        AbstractSyntaxTree tree = buildTree();
        SemanticLint linter = new SemanticLint(tree);
        System.out.println(linter.lint());
    }
}