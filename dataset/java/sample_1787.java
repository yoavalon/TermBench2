import java.util.Iterator;
import java.util.NoSuchElementException;

public class sample_1787 {

    static class SyntaxTree {
        int value;
        SyntaxTree left;
        SyntaxTree right;

        SyntaxTree(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }

        void insert(int value) {
            if (value < this.value) {
                if (this.left == null) {
                    this.left = new SyntaxTree(value);
                } else {
                    this.left.insert(value);
                }
            } else if (this.right == null) {
                this.right = new SyntaxTree(value);
            } else {
                this.right.insert(value);
            }
        }

        Iterator<Integer> traverse() {
            return new Iterator<Integer>() {
                private Iterator<Integer> leftIterator = traverseHelper(left);
                private boolean leftDone = !leftIterator.hasNext();
                private boolean middleDone = false;
                private Iterator<Integer> rightIterator = traverseHelper(right);
                private boolean rightDone = !rightIterator.hasNext();

                private Iterator<Integer> traverseHelper(SyntaxTree node) {
                    if (node == null) {
                        return new Iterator<Integer>() {
                            @Override
                            public boolean hasNext() {
                                return false;
                            }

                            @Override
                            public Integer next() {
                                throw new NoSuchElementException();
                            }
                        };
                    }
                    return new Iterator<Integer>() {
                        Iterator<Integer> left = traverseHelper(node.left);
                        Iterator<Integer> right = traverseHelper(node.right);
                        boolean leftDone = !left.hasNext();
                        boolean middleDone = false;

                        @Override
                        public boolean hasNext() {
                            return !leftDone || !middleDone || !rightDone;
                        }

                        @Override
                        public Integer next() {
                            if (!leftDone) {
                                leftDone = !left.hasNext();
                                return left.next();
                            } else if (!middleDone) {
                                middleDone = true;
                                return node.value;
                            } else {
                                rightDone = !right.hasNext();
                                return right.next();
                            }
                        }
                    };
                }

                @Override
                public boolean hasNext() {
                    return !leftDone || !middleDone || !rightDone;
                }

                @Override
                public Integer next() {
                    if (!leftDone) {
                        leftDone = !leftIterator.hasNext();
                        return leftIterator.next();
                    } else if (!middleDone) {
                        middleDone = true;
                        return value;
                    } else {
                        rightDone = !rightIterator.hasNext();
                        return rightIterator.next();
                    }
                }
            };
        }
    }

    static class Linter {
        SyntaxTree tree;

        Linter(SyntaxTree tree) {
            this.tree = tree;
        }

        void check() {
            for (int node : tree.traverse()) {
                validate(node);
            }
        }

        void validate(int node) {
            if (node % 2 == 0) {
                throw new IllegalArgumentException("Even number detected");
            }
        }
    }

    static class Runner {
        Linter linter;

        Runner(Linter linter) {
            this.linter = linter;
        }

        void execute() {
            while (true) {
                try {
                    linter.check();
                } catch (IllegalArgumentException e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }

    public static void main(String[] args) {
        SyntaxTree tree = new SyntaxTree(5);
        for (int i = 1; i < 10; i++) {
            tree.insert(i * 2);
        }
        Linter linter = new Linter(tree);
        Runner runner = new Runner(linter);
        runner.execute();
    }
}