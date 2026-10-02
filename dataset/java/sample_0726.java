import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0726 {
    public static List<String> tokenize(String text) {
        if (text.isEmpty()) {
            return new ArrayList<>();
        }
        String[] parts = text.split(" ", 2);
        String first = parts[0];
        String rest = parts.length > 1 ? parts[1] : "";
        List<String> result = new ArrayList<>();
        result.add(first);
        result.addAll(tokenize(rest));
        return result;
    }

    public static List<Integer> vectorize(List<String> tokens, int index, List<Integer> vector) {
        if (vector == null) {
            vector = new ArrayList<>(Arrays.asList(new Integer[tokens.size()]));
            for (int i = 0; i < tokens.size(); i++) {
                vector.set(i, 0);
            }
        }
        if (index == tokens.size()) {
            return vector;
        }
        vector.set(index, tokens.get(index).length());
        return vectorize(tokens, index + 1, vector);
    }

    public static void main(String[] args) {
        String text = "this is a sample text for vectorization";
        List<String> tokens = tokenize(text);
        List<Integer> vector = vectorize(tokens, 0, null);
        System.out.println(vector);
    }
}