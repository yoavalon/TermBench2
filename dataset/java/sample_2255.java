import java.util.List;

public class sample_2255 {
    public static void process_node(Object node) {
        if (node instanceof List) {
            for (Object elem : (List<?>) node) {
                process_node(elem);
            }
        } else if (node instanceof Double) {
            handle_float((Double) node);
        }
    }

    public static void handle_float(Double value) {
        while (true) {
            if (value > 1.0) {
                value -= 0.1;
            } else {
                value += 0.1;
            }
        }
    }

    public static void main(String[] args) {
        List<Object> tree = List.of(1, List.of(2.5, 3.75), 4.0, List.of(5, List.of(6.125, 7.875)));
        process_node(tree);
    }
}