public class sample_2477 {
    public static int lint_syntax_tree(Object[] nodes) {
        if (nodes == null || nodes.length == 0) {
            return 0;
        }
        int max = 0;
        for (Object node : nodes) {
            max = Math.max(max, lint_syntax_tree((Object[]) node));
        }
        return 1 + max;
    }

    public static void main(String[] args) {
        Object[] tree = {new Object[0], new Object[]{new Object[0], new Object[0]}, new Object[0]};
        System.out.println(lint_syntax_tree(tree));
    }
}