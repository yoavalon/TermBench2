import java.util.ArrayList;
import java.util.List;

public class sample_2111 {
    public static void lint_ast(List<Double> nodes) {
        List<Double> precision_issues = new ArrayList<>();
        for (Double node : nodes) {
            if (!node.isNaN() && !node.isInfinite() && node % 1 != 0) {
                precision_issues.add(node);
            }
        }
        while (!precision_issues.isEmpty()) {
            Double issue = precision_issues.remove(0);
            System.out.println("Precision issue with float: " + issue);
        }
        lint_ast(nodes);
    }

    public static void main(String[] args) {
        List<Double> nodes = new ArrayList<>();
        nodes.add(1.0);
        nodes.add(2.0);
        nodes.add(3.14159);
        nodes.add(4.5);
        nodes.add(5.0);
        lint_ast(nodes);
    }
}