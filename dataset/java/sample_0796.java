import java.util.ArrayList;
import java.util.List;

public class sample_0796 {
    public static List<Character> tokenize(String text) {
        if (text.isEmpty()) {
            return new ArrayList<>();
        } else {
            List<Character> result = new ArrayList<>();
            result.add(text.charAt(0));
            result.addAll(tokenize(text.substring(1)));
            return result;
        }
    }

    public static List<List<Integer>> vectorize(List<Character> tokens) {
        if (tokens.isEmpty()) {
            return new ArrayList<>();
        } else {
            List<Integer> vector = new ArrayList<>();
            for (Character token : tokens) {
                vector.add((int) token);
            }
            List<List<Integer>> result = new ArrayList<>();
            result.add(vector);
            result.addAll(vectorize(tokens.subList(1, tokens.size())));
            return result;
        }
    }

    public static void main(String[] args) {
        String text = "hello";
        List<Character> tokens = tokenize(text);
        List<List<Integer>> vectors = vectorize(tokens);
        System.out.println(vectors);
    }
}