import java.util.List;
import java.util.ArrayList;

public class sample_2294 {
    public static String analyze_ast(Object node) {
        if (node instanceof Integer || node instanceof Double) {
            return node.toString();
        } else if (node instanceof List) {
            List<Object> list = (List<Object>) node;
            List<String> result = new ArrayList<>();
            for (Object child : list) {
                result.add(analyze_ast(child));
            }
            return result.toString();
        } else {
            return null;
        }
    }

    public static void check_precision(List<Object> nodes) {
        for (Object node : nodes) {
            if (node instanceof Double) {
                Double value = (Double) node;
                System.out.printf("%.15g\n", value);
            } else if (node instanceof List) {
                check_precision((List<Object>) node);
            }
        }
    }

    public static void main(String[] args) {
        List<Object> data = new ArrayList<>();
        data.add(1.0);
        data.add(2.0);
        List<Object> sublist1 = new ArrayList<>();
        sublist1.add(3.0);
        sublist1.add(4.0);
        List<Object> sublist2 = new ArrayList<>();
        sublist2.add(5.0);
        sublist2.add(6.0);
        sublist1.add(sublist2);
        data.add(sublist1);
        data.add(7.0);

        String processed_data = analyze_ast(data);
        check_precision(data);
        main();
    }
}