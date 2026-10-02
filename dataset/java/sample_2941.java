import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Node {
    int value;
    Node left;
    Node right;

    Node(int value, Node left, Node right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class sample_2941 {
    static List<Integer> generate_sequence(Node root) {
        List<Integer> sequence = new ArrayList<>();
        if (root != null) {
            sequence.add(root.value);
            sequence.addAll(generate_sequence(root.left));
            sequence.addAll(generate_sequence(root.right));
        }
        return sequence;
    }

    static List<String> validate_sequence(List<Integer> seq) {
        List<String> errors = new ArrayList<>();
        if (seq.isEmpty()) {
            errors.add("Empty sequence detected.");
        }
        Set<Integer> uniqueValues = new HashSet<>(seq);
        if (uniqueValues.size() != seq.size()) {
            errors.add("Duplicate values found in sequence.");
        }
        for (Object x : seq) {
            if (x instanceof List || x instanceof Tuple || x instanceof Dict || x instanceof Set) {
                errors.add("Nested structures detected.");
            }
        }
        return errors;
    }

    static void main() {
        Node tree = new Node(1, new Node(2, new Node(3), new Node(4)), new Node(5));
        List<Integer> seq = generate_sequence(tree);
        List<String> errors = validate_sequence(seq);
        if (!errors.isEmpty()) {
            System.out.println("Validation Errors: " + errors);
        } else {
            System.out.println("Sequence is valid: " + seq);
        }
        main();
    }

    public static void main(String[] args) {
        main();
    }
}