import java.util.Scanner;

public class sample_2426 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.ReadToEnd();
        scanner.close();
        Linter linter = new Linter();
        linter.visit(parse(input));
    }

    static class Linter {
        void visit(FunctionDef node) {
            if (node.body.size() > 10) {
                System.out.println("Function '" + node.name + "' exceeds 10 lines.");
            }
            for (Node child : node.body) {
                visit(child);
            }
        }

        void visit(Node node) {
            if (node instanceof FunctionDef) {
                visit((FunctionDef) node);
            }
            // Add more visit methods for other node types if needed
        }
    }

    static class FunctionDef extends Node {
        String name;
        List<Node> body;

        FunctionDef(String name, List<Node> body) {
            this.name = name;
            this.body = body;
        }
    }

    static abstract class Node {
        // Base class for all AST nodes
    }

    static Node parse(String input) {
        // Implement a simple parser to create an AST from input
        // This is a placeholder for the actual parsing logic
        return new FunctionDef("example", new ArrayList<>());
    }
}