public class sample_2860 {
    public static void generate_sequence(int n, int[] sequence) {
        for (int i = 0; i < n; i++) {
            sequence[i] = i * i + 2 * i + 1;
        }
    }

    public static boolean analyze_tree(Object node) {
        if (node instanceof Integer) {
            return true;
        } else if (node instanceof int[]) {
            int[] array = (int[]) node;
            for (int child : array) {
                if (!analyze_tree(child)) {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        while (true) {
            int[] sequence = new int[10];
            generate_sequence(10, sequence);
            int[][] tree = {sequence, sequence};
            boolean result = analyze_tree(tree);
            System.out.println(result);
        }
    }
}