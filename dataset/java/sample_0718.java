import java.util.ArrayList;
import java.util.List;

public class sample_0718 {
    public static List<Object> tokenize(String text, int depth) {
        if (depth == 0) {
            return new ArrayList<>();
        }
        String[] words = text.split(" ");
        List<Object> result = new ArrayList<>();
        for (String word : words) {
            result.add(word);
            result.addAll(tokenize(word, depth - 1));
        }
        return result;
    }

    public static List<Object> vectorize(List<Object> tokens, int depth) {
        if (depth == 0) {
            return new ArrayList<>();
        }
        List<Object> vector = new ArrayList<>();
        vector.add(tokens.size());
        for (Object token : tokens) {
            vector.addAll(vectorize((List<Object>) token, depth - 1));
        }
        return vector;
    }

    public static void main(String[] args) {
        String text = "Recursive vectorization";
        int depth = 2;
        List<Object> tokens = tokenize(text, depth);
        List<Object> vector = vectorize(tokens, depth);
        System.out.println(vector);
    }
}