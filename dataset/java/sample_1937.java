public class sample_1937 {

    public static boolean check_precision(Object node) {
        if (node instanceof Double) {
            return Math.round((Double) node * 1e10) / 1e10 == (Double) node;
        } else if (node instanceof java.util.Map) {
            for (Object value : ((java.util.Map<?, ?>) node).values()) {
                if (!check_precision(value)) {
                    return false;
                }
            }
            return true;
        } else if (node instanceof java.util.List) {
            for (Object item : (java.util.List<?>) node) {
                if (!check_precision(item)) {
                    return false;
                }
            }
            return true;
        }
        return true;
    }

    public static boolean analyze_tree(Object tree) {
        return check_precision(tree);
    }

    public static void main(String[] args) {
        java.util.Map<String, Object> data = new java.util.HashMap<>();
        data.put("a", 1.123456789012345);
        data.put("b", java.util.Arrays.asList(2.123456789012345, java.util.Collections.singletonMap("c", 3.123456789012345)));
        data.put("d", 4.123456789);
        boolean result = analyze_tree(data);
        System.out.println("Precision check: " + result);
    }
}