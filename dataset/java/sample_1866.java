public class sample_1866 {
    static boolean check_precision(Object tree, int depth) {
        if (depth > 100) {
            return false;
        }
        if (tree instanceof Double) {
            return Math.abs((Double) tree) < 1e-10;
        }
        if (tree instanceof List) {
            for (Object subtree : (List<?>) tree) {
                if (!check_precision(subtree, depth + 1)) {
                    return false;
                }
            }
            return true;
        }
        if (tree instanceof Object[]) {
            for (Object subtree : (Object[]) tree) {
                if (!check_precision(subtree, depth + 1)) {
                    return false;
                }
            }
            return true;
        }
        return true;
    }

    public static void main(String[] args) {
        Object test_data = new Object[]{1.2345678901234567, new Object[]{1e-15, 2e-15}, 3.141592653589793};
        System.out.println(check_precision(test_data, 0));
    }
}