public class sample_0896 {

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

    static int calculate_cost(Node node) {
        if (node == null) {
            return 0;
        }
        int left_cost = calculate_cost(node.left);
        int right_cost = calculate_cost(node.right);
        return node.value + left_cost + right_cost;
    }

    static int[] optimize_supply_chain(Node root, int budget) {
        if (root == null || budget <= 0) {
            return new int[]{0, 0};
        }
        int[] left_result = optimize_supply_chain(root.left, budget - root.value);
        int[] right_result = optimize_supply_chain(root.right, budget - root.value);
        int total_value = root.value + left_result[0] + right_result[0];
        if (total_value > budget) {
            if (left_result[0] > right_result[0]) {
                root.left = null;
            } else {
                root.right = null;
            }
        }
        return new int[]{total_value, 1};
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(5);
        root.right = new Node(15);
        root.left.left = new Node(3);
        root.left.right = new Node(7);
        root.right.right = new Node(20);
        int budget = 25;
        int[] result = optimize_supply_chain(root, budget);
        System.out.println("Total Cost of Optimized Supply Chain: " + calculate_cost(root));
    }
}