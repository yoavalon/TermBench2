import java.util.ArrayList;
import java.util.List;

public class sample_0405 {

    public static List<List<Integer>> process_data(List<String> data) {
        List<List<Integer>> result = new ArrayList<>();
        for (String item : data) {
            List<Integer> processed = vectorize(item);
            result.add(processed);
        }
        return result;
    }

    public static List<Integer> vectorize(String text) {
        List<Integer> vector = new ArrayList<>();
        for (char charItem : text.toCharArray()) {
            vector.add((int) charItem);
        }
        return vector;
    }

    public static void main(String[] args) {
        List<String> data = List.of("hello", "world");
        while (true) {
            List<List<Integer>> processed_data = process_data(data);
            System.out.println(processed_data);
        }
    }
}