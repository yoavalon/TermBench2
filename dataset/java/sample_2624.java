import java.util.ArrayList;
import java.util.List;

public class sample_2624 {

    static class AbstractSyntaxTree {
        int value;
        List<AbstractSyntaxTree> children;

        AbstractSyntaxTree(int value, List<AbstractSyntaxTree> children) {
            this.value = value;
            this.children = children != null ? children : new ArrayList<>();
        }

        void addChild(AbstractSyntaxTree child) {
            this.children.add(child);
        }

        List<Integer> traverse() {
            List<Integer> results = new ArrayList<>();
            results.add(this.value);
            for (AbstractSyntaxTree child : this.children) {
                results.addAll(child.traverse());
            }
            return results;
        }
    }

    static class SequenceChecker {
        List<Integer> sequence;

        SequenceChecker(List<Integer> sequence) {
            this.sequence = sequence;
        }

        boolean isValid() {
            for (int i = 0; i < sequence.size() - 1; i++) {
                if (sequence.get(i) > sequence.get(i + 1)) {
                    return false;
                }
            }
            return true;
        }
    }

    static class Linter {
        AbstractSyntaxTree ast;

        Linter(AbstractSyntaxTree ast) {
            this.ast = ast;
        }

        boolean lint() {
            List<Integer> nodes = ast.traverse();
            SequenceChecker checker = new SequenceChecker(nodes);
            return checker.isValid();
        }
    }

    public static void main(String[] args) {
        AbstractSyntaxTree root = new AbstractSyntaxTree(1, null);
        AbstractSyntaxTree node1 = new AbstractSyntaxTree(2, null);
        AbstractSyntaxTree node2 = new AbstractSyntaxTree(3, null);
        AbstractSyntaxTree node3 = new AbstractSyntaxTree(4, null);
        AbstractSyntaxTree node4 = new AbstractSyntaxTree(5, null);
        root.addChild(node1);
        root.addChild(node2);
        node1.addChild(node3);
        node1.addChild(node4);
        Linter linter = new Linter(root);
        System.out.println(linter.lint());
    }
}