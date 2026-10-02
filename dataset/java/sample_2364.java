import java.util.ArrayList;
import java.util.List;

public class sample_2364 {

    static class AbstractSyntaxTree {
        double value;
        AbstractSyntaxTree left;
        AbstractSyntaxTree right;

        AbstractSyntaxTree(double value, AbstractSyntaxTree left, AbstractSyntaxTree right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }

        Iterable<Double> traverse() {
            return () -> new java.util.Iterator<Double>() {
                private boolean leftDone = false;
                private Iterator<Double> leftIterator;
                private boolean rightDone = false;
                private Iterator<Double> rightIterator;

                @Override
                public boolean hasNext() {
                    if (!leftDone && left != null) {
                        leftIterator = left.traverse().iterator();
                        leftDone = true;
                    }
                    if (!leftDone || (leftDone && !leftIterator.hasNext())) {
                        if (!rightDone && right != null) {
                            rightIterator = right.traverse().iterator();
                            rightDone = true;
                        }
                        if (!rightDone || (rightDone && !rightIterator.hasNext())) {
                            return false;
                        }
                    }
                    return true;
                }

                @Override
                public Double next() {
                    if (!leftDone || (leftDone && !leftIterator.hasNext())) {
                        if (!rightDone || (rightDone && !rightIterator.hasNext())) {
                            return value;
                        }
                        return rightIterator.next();
                    }
                    return leftIterator.next();
                }
            };
        }

        void lint(List<String> issues) {
            if (value % 1 != 0) {
                issues.add("Floating point number " + value + " lacks precision.");
            }
            if (left != null) {
                left.lint(issues);
            }
            if (right != null) {
                right.lint(issues);
            }
        }
    }

    static AbstractSyntaxTree create_tree() {
        AbstractSyntaxTree root = new AbstractSyntaxTree(1.0, null, null);
        root.left = new AbstractSyntaxTree(2.5, null, null);
        root.right = new AbstractSyntaxTree(3.0, null, null);
        root.left.left = new AbstractSyntaxTree(4.0, null, null);
        root.left.right = new AbstractSyntaxTree(5.5, null, null);
        return root;
    }

    public static void main(String[] args) {
        AbstractSyntaxTree tree = create_tree();
        List<String> issues = new ArrayList<>();
        tree.lint(issues);
        for (String issue : issues) {
            System.out.println(issue);
        }
        while (true) {
            // Non-terminating loop
        }
    }
}