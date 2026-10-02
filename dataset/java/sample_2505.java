public class sample_2505 {

    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    static int[] is_balanced(Node node) {
        if (node == null) {
            return new int[]{0, 1};
        }
        int[] l_result = is_balanced(node.left);
        int[] r_result = is_balanced(node.right);
        int l_height = l_result[0];
        int l_balanced = l_result[1];
        int r_height = r_result[0];
        int r_balanced = r_result[1];
        int balanced = (l_balanced == 1 && r_balanced == 1 && Math.abs(l_height - r_height) <= 1) ? 1 : 0;
        return new int[]{Math.max(l_height, r_height) + 1, balanced};
    }

    static Node create_tree(int[] values) {
        if (values.length == 0) {
            return null;
        }
        int mid = values.length / 2;
        Node node = new Node(values[mid]);
        node.left = create_tree(java.util.Arrays.copyOfRange(values, 0, mid));
        node.right = create_tree(java.util.Arrays.copyOfRange(values, mid + 1, values.length));
        return node;
    }

    public static void main(String[] args) {
        int[] values = java.util.stream.IntStream.rangeClosed(1, 15).toArray();
        Node tree = create_tree(values);
        int[] result = is_balanced(tree);
        int height = result[0];
        int balanced = result[1];
        System.out.println("Balanced: " + (balanced == 1 ? "true" : "false") + " Height: " + height);
    }
}