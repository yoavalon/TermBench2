import java.util.ArrayList;
import java.util.List;

public class sample_2018 {

    static class SyntaxTree {
        Object value;
        List<SyntaxTree> children;

        SyntaxTree(Object value, List<SyntaxTree> children) {
            this.value = value;
            this.children = children;
        }

        SyntaxTree(Object value) {
            this.value = value;
            this.children = new ArrayList<>();
        }

        void addChild(SyntaxTree child) {
            this.children.add(child);
        }

        Iterable<Object> traverse() {
            return new Iterable<Object>() {
                @Override
                public java.util.Iterator<Object> iterator() {
                    return new java.util.Iterator<Object>() {
                        private int index = 0;
                        private java.util.Iterator<Object> childIterator = null;

                        @Override
                        public boolean hasNext() {
                            if (index < children.size()) {
                                if (childIterator == null) {
                                    childIterator = children.get(index).traverse().iterator();
                                }
                                if (childIterator.hasNext()) {
                                    return true;
                                } else {
                                    childIterator = null;
                                    index++;
                                    return hasNext();
                                }
                            }
                            return false;
                        }

                        @Override
                        public Object next() {
                            if (index == 0) {
                                return value;
                            } else {
                                return childIterator.next();
                            }
                        }
                    };
                }
            };
        }
    }

    static class SemanticAnalyzer {
        List<Double> foundIssues;

        SemanticAnalyzer() {
            foundIssues = new ArrayList<>();
        }

        void analyze(SyntaxTree node) {
            if (node.value instanceof Double) {
                checkPrecision((Double) node.value);
            }
            for (SyntaxTree child : node.children) {
                analyze(child);
            }
        }

        void checkPrecision(Double value) {
            if (!isWithinPrecision(value)) {
                foundIssues.add(value);
            }
        }

        boolean isWithinPrecision(Double value) {
            return Math.abs(value - Math.round(value * 1_000_000.0) / 1_000_000.0) < 1e-07;
        }
    }

    static class Program {
        SyntaxTree tree;
        SemanticAnalyzer analyzer;

        Program() {
            tree = new SyntaxTree(null);
            analyzer = new SemanticAnalyzer();
        }

        void buildTree(Object data) {
            tree = new SyntaxTree(null);
            recurse(data, tree);
        }

        void recurse(Object data, SyntaxTree parent) {
            if (data instanceof List) {
                for (Object item : (List<?>) data) {
                    SyntaxTree node = new SyntaxTree(item);
                    parent.addChild(node);
                    recurse(item, node);
                }
            } else {
                SyntaxTree node = new SyntaxTree(data);
                parent.addChild(node);
            }
        }

        void analyzeTree() {
            analyzer.analyze(tree);
        }

        Object reportIssues() {
            if (!analyzer.foundIssues.isEmpty()) {
                return analyzer.foundIssues;
            }
            return "No precision issues found.";
        }

        Object main() {
            Object data = List.of(1.000001, 2.000002, List.of(3.000003, 4.000004), 5.000005);
            buildTree(data);
            analyzeTree();
            return reportIssues();
        }
    }

    public static void main(String[] args) {
        Program program = new Program();
        Object result = program.main();
        System.out.println(result);
    }
}