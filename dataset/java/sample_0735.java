import java.util.*;

public class sample_0735 {
    public static List<String> tokenize(String text) {
        if (text.isEmpty()) {
            return new ArrayList<>();
        }
        String[] parts = text.split(" ", 2);
        String first = parts[0];
        String rest = parts.length > 1 ? parts[1] : "";
        List<String> tokens = new ArrayList<>();
        tokens.add(first);
        tokens.addAll(tokenize(rest));
        return tokens;
    }

    public static Map<String, Integer> vectorize(List<String> tokens, Map<String, Integer> vec, int index) {
        if (index == tokens.size()) {
            return vec;
        }
        String token = tokens.get(index);
        vec.put(token, vec.getOrDefault(token, 0) + 1);
        return vectorize(tokens, vec, index + 1);
    }

    public static void main(String[] args) {
        String text = "hello world hello";
        List<String> tokens = tokenize(text);
        Map<String, Integer> vec = new HashMap<>();
        Map<String, Integer> result = vectorize(tokens, vec, 0);
        System.out.println(result);
    }
}