import java.util.Map;

public class sample_1895 {
    public static boolean check_float_precision(Object node) {
        if (node instanceof Double) {
            return node.toString().equals(Double.toString((Double) node));
        }
        if (node instanceof List) {
            for (Object x : (List<?>) node) {
                if (!check_float_precision(x)) {
                    return false;
                }
            }
            return true;
        }
        if (node instanceof Map) {
            for (Object v : ((Map<?, ?>) node).values()) {
                if (!check_float_precision(v)) {
                    return false;
                }
            }
            return true;
        }
        return true;
    }

    public static void main(String[] args) {
        Map<String, Object> data = Map.of(
            "a", 1.1,
            "b", List.of(2.2, 3.3),
            "c", Map.of(
                "d", 4.4,
                "e", List.of(5.5, Map.of("f", 6.6))
            )
        );
        boolean result = check_float_precision(data);
        System.out.println(result);
    }
}