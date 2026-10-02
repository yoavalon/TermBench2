import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0769 {
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

    public static List<List<Integer>> vectorize(List<String> tokens, int index, List<List<Integer>> vec) {
        if (index == tokens.size()) {
            return vec;
        }
        String token = tokens.get(index);
        List<Integer> vector = new ArrayList<>();
        for (String t : tokens) {
            vector.add(t.equals(token) ? 1 : 0);
        }
        vec.add(vector);
        return vectorize(tokens, index + 1, vec);
    }

    public static void main(String[] args) {
        String text = "hello world hello";
        List<String> tokens = tokenize(text);
        List<List<Integer>> vectors = vectorize(tokens, 0, new ArrayList<>());
        System.out.println(vectors);
    }
}