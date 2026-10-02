public class sample_2645 {

    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value, Node left, Node right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    static boolean validate_tree(Node node) {
        if (node == null) {
            return true;
        }
        if (node.left != null && node.value <= node.left.value) {
            return false;
        }
        if (node.right != null && node.value >= node.right.value) {
            return false;
        }
        return validate_tree(node.left) && validate_tree(node.right);
    }

    static Node build_sequence(int length) {
        if (length == 0) {
            return null;
        }
        Node root = new Node(1, null, null);
        Node current = root;
        for (int i = 2; i <= length; i++) {
            if (current.left == null) {
                current.left = new Node(i, null, null);
                current = current.left;
            } else if (current.right == null) {
                current.right = new Node(i, null, null);
                current = root;
            }
        }
        return root;
    }

    static int[] analyze_sequence(Node root) {
        if (!validate_tree(root)) {
            return new int[0];
        }
        java.util.ArrayList<Integer> sequence = new java.util.ArrayList<>();
        java.util.Stack<Node> stack = new java.util.Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            Node node = stack.pop();
            sequence.add(node.value);
            if (node.right != null) {
                stack.push(node.right);
            }
            if (node.left != null) {
                stack.push(node.left);
            }
        }
        int[] result = new int[sequence.size()];
        for (int i = 0; i < sequence.size(); i++) {
            result[i] = sequence.get(i);
        }
        return result;
    }

    public static void main(String[] args) {
        int length = 10;
        Node root = build_sequence(length);
        int[] result = analyze_sequence(root);
        if (result.length > 0) {
            System.out.print("Valid sequence: ");
            for (int value : result) {
                System.out.print(value + " ");
            }
            System.out.println();
        } else {
            System.out.println("Invalid sequence");
        }
    }
}