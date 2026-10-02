public class sample_1819 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        Object tree = new Object[]{3.141592653589793, new Object[]{2.718281828459045, 1.618033988749895}, 0.5772156649015329};
        Object result = lint_syntax(tree);
        System.out.println(result);
    }

    public static Object lint_syntax(Object tree) {
        if (tree instanceof Double) {
            return Math.round((Double) tree * 1e6) / 1e6;
        }
        if (tree instanceof Object[]) {
            Object[] array = (Object[]) tree;
            Object[] result = new Object[array.length];
            for (int i = 0; i < array.length; i++) {
                result[i] = lint_syntax(array[i]);
            }
            return result;
        }
        return tree;
    }
}