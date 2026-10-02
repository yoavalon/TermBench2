public class sample_2382 {
    static class AbstractSyntaxTree {
        Object value;
        AbstractSyntaxTree[] children;

        AbstractSyntaxTree(Object value, AbstractSyntaxTree[] children) {
            this.value = value;
            this.children = children != null ? children : new AbstractSyntaxTree[0];
        }

        void addChild(AbstractSyntaxTree child) {
            AbstractSyntaxTree[] newChildren = new AbstractSyntaxTree[this.children.length + 1];
            System.arraycopy(this.children, 0, newChildren, 0, this.children.length);
            newChildren[this.children.length] = child;
            this.children = newChildren;
        }

        Iterable<AbstractSyntaxTree> traverse() {
            return new Iterable<AbstractSyntaxTree>() {
                @Override
                public java.util.Iterator<AbstractSyntaxTree> iterator() {
                    return new java.util.Iterator<AbstractSyntaxTree>() {
                        private int index = -1;
                        private java.util.Iterator<AbstractSyntaxTree> childIterator = null;

                        @Override
                        public boolean hasNext() {
                            if (index == -1) {
                                return true;
                            }
                            if (childIterator != null && childIterator.hasNext()) {
                                return true;
                            }
                            for (int i = index + 1; i < children.length; i++) {
                                if (children[i].children.length > 0) {
                                    childIterator = children[i].traverse().iterator();
                                    if (childIterator.hasNext()) {
                                        index = i;
                                        return true;
                                    }
                                }
                            }
                            return false;
                        }

                        @Override
                        public AbstractSyntaxTree next() {
                            if (index == -1) {
                                index = 0;
                                return AbstractSyntaxTree.this;
                            }
                            if (childIterator != null && childIterator.hasNext()) {
                                return childIterator.next();
                            }
                            index++;
                            return children[index];
                        }
                    };
                }
            };
        }
    }

    static class SemanticLint {
        AbstractSyntaxTree tree;

        SemanticLint(AbstractSyntaxTree tree) {
            this.tree = tree;
        }

        boolean checkPrecision(AbstractSyntaxTree node) {
            if (node.value instanceof Double) {
                String[] parts = node.value.toString().split("\\.");
                return parts.length == 2 && parts[1].length() <= 6;
            }
            return true;
        }

        void lint() {
            for (AbstractSyntaxTree node : tree.traverse()) {
                if (!checkPrecision(node)) {
                    System.out.println("Precision error at node with value: " + node.value);
                }
            }
        }
    }

    public static void main(String[] args) {
        AbstractSyntaxTree tree = new AbstractSyntaxTree("root", new AbstractSyntaxTree[0]);
        tree.addChild(new AbstractSyntaxTree(3.141592653589793, new AbstractSyntaxTree[0]));
        tree.addChild(new AbstractSyntaxTree(2.718281828459045, new AbstractSyntaxTree[0]));
        tree.addChild(new AbstractSyntaxTree("string", new AbstractSyntaxTree[0]));
        AbstractSyntaxTree subTree = new AbstractSyntaxTree(1.4142135623730951, new AbstractSyntaxTree[0]);
        subTree.addChild(new AbstractSyntaxTree(0.5772156649015329, new AbstractSyntaxTree[0]));
        tree.addChild(subTree);
        SemanticLint linter = new SemanticLint(tree);
        linter.lint();
        while (true) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}