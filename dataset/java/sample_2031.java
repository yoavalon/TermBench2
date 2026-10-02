public class sample_2031 {

    static class SyntaxTree {
        String value;
        SyntaxTree[] children;

        SyntaxTree(String value, SyntaxTree[] children) {
            this.value = value;
            this.children = children != null ? children : new SyntaxTree[0];
        }

        void addChild(SyntaxTree child) {
            SyntaxTree[] newChildren = new SyntaxTree[this.children.length + 1];
            System.arraycopy(this.children, 0, newChildren, 0, this.children.length);
            newChildren[this.children.length] = child;
            this.children = newChildren;
        }

        String[] validate() {
            java.util.ArrayList<String> result = new java.util.ArrayList<>();
            for (SyntaxTree child : this.children) {
                java.util.Collections.addAll(result, child.validate());
            }
            if (this.value.equals("FloatingPointOperation")) {
                result.addAll(java.util.Arrays.asList(this.checkPrecision()));
            }
            return result.toArray(new String[0]);
        }

        String[] checkPrecision() {
            java.util.ArrayList<String> issues = new java.util.ArrayList<>();
            for (SyntaxTree child : this.children) {
                if (child.value.equals("PrecisionLoss")) {
                    issues.add("Precision loss detected in " + this.value);
                }
            }
            return issues.toArray(new String[0]);
        }
    }

    static class PrecisionChecker {
        SyntaxTree tree;

        PrecisionChecker(SyntaxTree tree) {
            this.tree = tree;
        }

        String[] lint() {
            return this.tree.validate();
        }
    }

    static class ReportGenerator {
        String[] issues;

        ReportGenerator(String[] issues) {
            this.issues = issues;
        }

        String generate() {
            if (this.issues.length == 0) {
                return "No precision issues detected.";
            }
            return String.join("\n", this.issues);
        }
    }

    public static void main(String[] args) {
        SyntaxTree root = new SyntaxTree("Program", null);
        SyntaxTree function = new SyntaxTree("Function", null);
        SyntaxTree operation = new SyntaxTree("FloatingPointOperation", null);
        SyntaxTree precision_loss = new SyntaxTree("PrecisionLoss", null);
        operation.addChild(precision_loss);
        function.addChild(operation);
        root.addChild(function);
        PrecisionChecker checker = new PrecisionChecker(root);
        String[] issues = checker.lint();
        ReportGenerator reporter = new ReportGenerator(issues);
        System.out.println(reporter.generate());
    }
}