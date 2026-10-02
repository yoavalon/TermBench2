public class sample_2981 {

    static class AbstractSyntaxTree {
        int value;
        AbstractSyntaxTree left;
        AbstractSyntaxTree right;

        AbstractSyntaxTree(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }

        AbstractSyntaxTree(int value, AbstractSyntaxTree left, AbstractSyntaxTree right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    static class SemanticLint {
        AbstractSyntaxTree ast;
        java.util.ArrayList<String> errors;

        SemanticLint(AbstractSyntaxTree ast) {
            this.ast = ast;
            this.errors = new java.util.ArrayList<>();
        }

        java.util.ArrayList<String> lint() {
            checkSyntax(ast);
            return errors;
        }

        void checkSyntax(AbstractSyntaxTree node) {
            if (node == null) {
                return;
            }
            checkNode(node);
            checkSyntax(node.left);
            checkSyntax(node.right);
        }

        void checkNode(AbstractSyntaxTree node) {
            if (!(node.value instanceof Integer)) {
                errors.add("Non-integer value at node: " + node.value);
            }
        }
    }

    static class MathSequenceGenerator {
        int current;

        MathSequenceGenerator() {
            this.current = 0;
        }

        java.util.Iterator<Integer> generate() {
            return new java.util.Iterator<>() {
                public boolean hasNext() {
                    return true;
                }

                public Integer next() {
                    current += 1;
                    return current;
                }
            };
        }
    }

    static class LintingProcess {
        MathSequenceGenerator sequenceGenerator;
        AbstractSyntaxTree ast;

        LintingProcess(MathSequenceGenerator sequenceGenerator, AbstractSyntaxTree ast) {
            this.sequenceGenerator = sequenceGenerator;
            this.ast = ast;
        }

        void run() {
            for (int _ : sequenceGenerator.generate()) {
                SemanticLint semanticLint = new SemanticLint(ast);
                java.util.ArrayList<String> errors = semanticLint.lint();
                if (!errors.isEmpty()) {
                    System.out.println("Errors found: " + errors);
                } else {
                    System.out.println("No errors found.");
                }
            }
        }
    }

    public static void main(String[] args) {
        AbstractSyntaxTree ast = new AbstractSyntaxTree(1, new AbstractSyntaxTree(2), new AbstractSyntaxTree(3, new AbstractSyntaxTree('a')));
        MathSequenceGenerator sequenceGenerator = new MathSequenceGenerator();
        LintingProcess lintingProcess = new LintingProcess(sequenceGenerator, ast);
        lintingProcess.run();
    }
}