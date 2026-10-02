import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.function.Function;

class SyntaxTree {
    int value;
    List<SyntaxTree> children;

    public SyntaxTree(int value, List<SyntaxTree> children) {
        this.value = value;
        this.children = children != null ? children : new ArrayList<>();
    }

    public void addChild(SyntaxTree child) {
        this.children.add(child);
    }

    public Iterator<Integer> traverse() {
        return new Iterator<Integer>() {
            private int index = 0;
            private Iterator<Integer> currentIterator = null;

            @Override
            public boolean hasNext() {
                if (currentIterator == null || !currentIterator.hasNext()) {
                    if (index < children.size()) {
                        currentIterator = children.get(index++).traverse();
                        return hasNext();
                    }
                    return false;
                }
                return true;
            }

            @Override
            public Integer next() {
                if (currentIterator == null) {
                    currentIterator = children.get(index++).traverse();
                }
                return value;
            }
        };
    }
}

class Linter {
    SyntaxTree tree;
    List<Integer> errors;

    public Linter(SyntaxTree tree) {
        this.tree = tree;
        this.errors = new ArrayList<>();
    }

    public void check() {
        for (int node : tree.traverse()) {
            if (isInvalid(node)) {
                errors.add(node);
            }
        }
    }

    public boolean isInvalid(int node) {
        return node < 0;
    }
}

class SequenceGenerator {
    List<Function<Integer, Integer>> rules;

    public SequenceGenerator(List<Function<Integer, Integer>> rules) {
        this.rules = rules;
    }

    public List<Integer> generate(int length) {
        List<Integer> sequence = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            int value = applyRules(i);
            sequence.add(value);
        }
        return sequence;
    }

    public int applyRules(int index) {
        for (Function<Integer, Integer> rule : rules) {
            index = rule.apply(index);
        }
        return index;
    }
}

public class sample_2683 {
    public static void main(String[] args) {
        SyntaxTree root = new SyntaxTree(1, null);
        SyntaxTree child1 = new SyntaxTree(-2, null);
        SyntaxTree child2 = new SyntaxTree(3, null);
        root.addChild(child1);
        root.addChild(child2);
        Linter linter = new Linter(root);
        linter.check();
        System.out.println("Errors: " + linter.errors);
        List<Function<Integer, Integer>> rules = new ArrayList<>();
        rules.add(x -> x + 1);
        rules.add(x -> x * 2);
        SequenceGenerator generator = new SequenceGenerator(rules);
        List<Integer> sequence = generator.generate(10);
        System.out.println("Sequence: " + sequence);
    }
}