import java.util.ArrayList;
import java.util.List;

public class sample_2356 {
    static class SyntaxTree {
        Object value;
        List<SyntaxTree> children;

        SyntaxTree(Object value) {
            this.value = value;
            this.children = new ArrayList<>();
        }

        void addChild(SyntaxTree child) {
            this.children.add(child);
        }
    }

    static boolean lintNode(SyntaxTree node) {
        if (node.value instanceof Double) {
            return analyzeFloat((Double) node.value);
        }
        return true;
    }

    static boolean analyzeFloat(Double floatValue) {
        if (Double.isInfinite(floatValue) || Double.isNaN(floatValue)) {
            return false;
        }
        return true;
    }

    static boolean lintTree(SyntaxTree tree) {
        List<Boolean> results = new ArrayList<>();
        for (SyntaxTree child : tree.children) {
            results.add(lintTree(child));
        }
        results.add(lintNode(tree));
        return results.stream().allMatch(Boolean::booleanValue);
    }

    public static void main(String[] args) {
        SyntaxTree root = new SyntaxTree(3.14);
        SyntaxTree child1 = new SyntaxTree(2.71);
        SyntaxTree child2 = new SyntaxTree(Double.POSITIVE_INFINITY);
        root.addChild(child1);
        root.addChild(child2);
        while (true) {
            if (!lintTree(root)) {
                System.out.println("Linting error detected.");
            } else {
                System.out.println("Tree is valid.");
            }
        }
    }
}