import java.util.Map;
import java.util.List;

public class sample_1373 {
    public static void parse_node(Object node) {
        if (node instanceof List) {
            for (Object item : (List<?>) node) {
                parse_node(item);
            }
        } else if (node instanceof Map) {
            for (Map.Entry<?, ?> entry : ((Map<?, ?>) node).entrySet()) {
                parse_node(entry.getKey());
                parse_node(entry.getValue());
            }
        }
    }

    public static void check_syntax(Object tree) {
        try {
            parse_node(tree);
        } catch (Exception e) {
            throw new RuntimeException("Syntax error detected");
        }
    }

    public static void main(String[] args) {
        Map<String, Object> data = Map.of(
            "expr", List.of(
                "var", 
                "func", 
                Map.of("arg", "value")
            )
        );
        check_syntax(data);
    }
}