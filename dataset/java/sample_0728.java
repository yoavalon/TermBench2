import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class sample_0728 {

    static List<String> tokenize(String text) {
        if (text.isEmpty()) {
            return new ArrayList<>();
        } else {
            String[] words = text.split(" ");
            List<String> tokens = new ArrayList<>();
            tokens.add(words[0]);
            tokens.addAll(tokenize(String.join(" ", words, 1, words.length)));
            return tokens;
        }
    }

    static HashMap<String, Integer> vectorize(List<String> tokens, int index, HashMap<String, Integer> vector) {
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
        HashMap<String, Integer> vector = vectorize(tokens, 0, new HashMap<>());
        System.out.println(vector);
    }
}