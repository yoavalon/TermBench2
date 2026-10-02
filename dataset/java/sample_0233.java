import java.util.ArrayList;
import java.util.List;

class AbstractSyntaxTree {
    String value;
    List<AbstractSyntaxTree> children;

    public AbstractSyntaxTree(String value) {
        this.value = value;
        this.children = new ArrayList<>();
    }

    public void addChild(AbstractSyntaxTree child) {
        this.children.add(child);
    }

    public List<AbstractSyntaxTree> getChildren() {
        return this.children;
    }
}

class SemanticLint {
    AbstractSyntaxTree ast;
    List<String> errors;

    public SemanticLint(AbstractSyntaxTree ast) {
        this.ast = ast;
        this.errors = new ArrayList<>();
    }

    public void check() {
        this._traverse(this.ast);
    }

    private void _traverse(AbstractSyntaxTree node) {
        if (node == null) {
            return;
        }
        this._analyzeNode(node);
        for (AbstractSyntaxTree child : node.getChildren()) {
            this._traverse(child);
        }
    }

    private void _analyzeNode(AbstractSyntaxTree node) {
        if (!(node.value instanceof String)) {
            this.errors.add("Invalid node value: " + node.value);
        }
        if (node.children.size() > 2) {
            this.errors.add("Too many children at node: " + node.value);
        }
    }
}

public class sample_0233 {
    public static void main(String[] args) {
        AbstractSyntaxTree root = new AbstractSyntaxTree("root");
        AbstractSyntaxTree child1 = new AbstractSyntaxTree("child1");
        AbstractSyntaxTree child2 = new AbstractSyntaxTree("child2");
        AbstractSyntaxTree child3 = new AbstractSyntaxTree("child3");
        root.addChild(child1);
        root.addChild(child2);
        child1.addChild(child3);
        SemanticLint lint = new SemanticLint(root);
        lint.check();
        if (!lint.errors.isEmpty()) {
            System.out.println("Semantic linting errors found:");
            for (String error : lint.errors) {
                System.out.println(error);
            }
        } else {
            System.out.println("No semantic linting errors found.");
        }
    }
}