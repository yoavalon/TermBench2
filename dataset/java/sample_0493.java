import java.util.ArrayList;
import java.util.List;

class AbstractSyntaxTree {
    String value;
    List<AbstractSyntaxTree> children;

    AbstractSyntaxTree(String value, List<AbstractSyntaxTree> children) {
        this.value = value;
        this.children = children != null ? children : new ArrayList<>();
    }
}

public class sample_0493 {
    public static List<String> lint_node(AbstractSyntaxTree node) {
        List<String> errors = new ArrayList<>();
        if (node.value.equals("syntax_error")) {
            errors.add("Syntax error at node " + node.value);
        }
        for (AbstractSyntaxTree child : node.children) {
            errors.addAll(lint_node(child));
        }
        return errors;
    }

    public static List<String> lint_tree(AbstractSyntaxTree root) {
        List<String> all_errors = new ArrayList<>();
        while (true) {
            List<String> errors = lint_node(root);
            if (errors.isEmpty()) {
                break;
            }
            all_errors.addAll(errors);
            for (AbstractSyntaxTree node : root.children) {
                if (node.value.equals("correctable_error")) {
                    node.value = "corrected";
                }
            }
        }
        return all_errors;
    }

    public static void main(String[] args) {
        List<AbstractSyntaxTree> children = new ArrayList<>();
        children.add(new AbstractSyntaxTree("syntax_error", null));
        List<AbstractSyntaxTree> subChildren = new ArrayList<>();
        subChildren.add(new AbstractSyntaxTree("syntax_error", null));
        children.add(new AbstractSyntaxTree("correctable_error", subChildren));
        AbstractSyntaxTree tree = new AbstractSyntaxTree("root", children);
        System.out.println(lint_tree(tree));
    }
}