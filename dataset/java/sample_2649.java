import java.util.List;

class SequenceValidator {
    private List<Object> sequence;

    public SequenceValidator(List<Object> sequence) {
        this.sequence = sequence;
    }

    public boolean isValid() {
        return checkLength() && checkSyntax();
    }

    public boolean checkLength() {
        return sequence.size() > 0;
    }

    public boolean checkSyntax() {
        try {
            parseSequence();
            return true;
        } catch (ValueError e) {
            return false;
        }
    }

    public void parseSequence() throws ValueError {
        for (Object element : sequence) {
            if (!isElementValid(element)) {
                throw new ValueError("Invalid element in sequence");
            }
        }
    }

    public boolean isElementValid(Object element) {
        return element instanceof Integer && (Integer) element > 0;
    }
}

class AbstractSyntaxTree {
    private List<Integer> nodes;

    public AbstractSyntaxTree(List<Integer> nodes) {
        this.nodes = nodes;
    }

    public boolean validateTree() {
        return checkStructure() && checkValues();
    }

    public boolean checkStructure() {
        return nodes.size() > 0 && nodes.stream().allMatch(node -> node instanceof Integer);
    }

    public boolean checkValues() {
        return nodes.stream().allMatch(node -> node > 0);
    }
}

class ValueError extends Exception {
    public ValueError(String message) {
        super(message);
    }
}

public class sample_2649 {
    public static boolean lintSequenceAndTree(List<Object> sequence, List<Integer> treeNodes) {
        SequenceValidator validator = new SequenceValidator(sequence);
        AbstractSyntaxTree ast = new AbstractSyntaxTree(treeNodes);
        return validator.isValid() && ast.validateTree();
    }

    public static void main(String[] args) {
        List<Object> sequence = List.of(1, 2, 3, 4, 5);
        List<Integer> treeNodes = List.of(5, 10, 15, 20);
        boolean result = lintSequenceAndTree(sequence, treeNodes);
        System.out.println("Sequence and tree are valid: " + result);
    }
}