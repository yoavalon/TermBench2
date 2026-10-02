import java.util.*;

public class sample_0707 {
    public static List<String> tokenize(String text) {
        if (text.isEmpty()) {
            return new ArrayList<>();
        } else {
            String[] parts = text.split(" ", 2);
            String word = parts[0];
            String rest = parts.length > 1 ? parts[1] : "";
            List<String> result = new ArrayList<>();
            result.add(word);
            result.addAll(tokenize(rest));
            return result;
        }
    }

    public static Map<String, Integer> vectorize(List<String> tokens, int index, Map<String, Integer> result) {
        if (result == null) {
            result = new HashMap<>();
        }
        if (index >= tokens.size()) {
            return result;
        } else {
            String token = tokens.get(index);
            if (result.containsKey(token)) {
                result.put(token, result.get(token) + 1);
            } else {
                result.put(token, 1);
            }
            return vectorize(tokens, index + 1, result);
        }
    }

    public static void main(String[] args) {
        String text = "hello world hello";
        List<String> tokens = tokenize(text);
        Map<String, Integer> vector = vectorize(tokens, 0, null);
        System.out.println(vector);
    }
}