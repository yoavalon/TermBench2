import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Arrays;

public class sample_0783 {
    public static List<String> tokenize(String text) {
        if (text.isEmpty()) {
            return Arrays.asList();
        } else {
            String[] parts = text.split("\\s+", 2);
            String word = parts[0];
            String rest = parts.length > 1 ? parts[1] : "";
            return Arrays.asList(word).addAll(tokenize(rest));
        }
    }

    public static Map<String, Integer> vectorize(List<String> tokens, int index, Map<String, Integer> vector) {
        if (index == tokens.size()) {
            return vector;
        } else {
            String token = tokens.get(index);
            vector.put(token, vector.getOrDefault(token, 0) + 1);
            return vectorize(tokens, index + 1, vector);
        }
    }

    public static void main(String[] args) {
        String text = "hello world hello";
        List<String> tokens = tokenize(text);
        Map<String, Integer> vector = vectorize(tokens, 0, new HashMap<>());
        System.out.println(vector);
    }
}