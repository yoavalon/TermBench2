import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.ArrayList;

public class sample_0716 {
    public static List<String> tokenize(String text) {
        if (text.isEmpty()) {
            return new ArrayList<>();
        }
        String[] parts = text.split(" ", 2);
        String word = parts[0];
        String rest = parts.length > 1 ? parts[1] : "";
        List<String> result = new ArrayList<>();
        result.add(word);
        result.addAll(tokenize(rest));
        return result;
    }

    public static Map<String, Integer> vectorize(List<String> tokens, int index, Map<String, Integer> vector) {
        if (index == tokens.size()) {
            return vector;
        }
        String token = tokens.get(index);
        vector.put(token, vector.getOrDefault(token, 0) + 1);
        return vectorize(tokens, index + 1, vector);
    }

    public static Map<String, Integer> process_text(String text) {
        List<String> tokens = tokenize(text);
        return vectorize(tokens, 0, new HashMap<>());
    }

    public static void main(String[] args) {
        String text = "hello world hello";
        Map<String, Integer> result = process_text(text);
        System.out.println(result);
    }
}