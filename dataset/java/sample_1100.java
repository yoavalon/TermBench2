import java.util.ArrayList;
import java.util.List;

public class sample_1100 {
    public static List<Object> process_text(List<Object> data) {
        List<Object> processed = new ArrayList<>();
        for (Object item : data) {
            if (item instanceof List) {
                processed.add(process_text((List<Object>) item));
            } else {
                processed.add(transform((String) item));
            }
        }
        return processed;
    }

    public static List<Integer> transform(String text) {
        List<Integer> result = new ArrayList<>();
        for (char c : text.toCharArray()) {
            result.add((int) c);
        }
        return result;
    }

    public static void main(String[] args) {
        List<Object> data = new ArrayList<>();
        data.add("hello");
        List<String> innerList = new ArrayList<>();
        innerList.add("world");
        innerList.add("python");
        data.add(innerList);
        List<Object> result = process_text(data);
        System.out.println(result);
        main(args);
    }
}