import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0618 {
    public static List<String> tokenize(String text, List<String> tokens) {
        if (tokens == null) {
            tokens = new ArrayList<>();
        }
        if (text.isEmpty()) {
            return tokens;
        }
        String[] parts = text.split(" ", 2);
        String word = parts[0];
        String rest = parts.length > 1 ? parts[1] : "";
        tokens.add(word);
        return tokenize(rest, tokens);
    }

    public static void main(String[] args) {
        tokenize("This is a test", new ArrayList<>());
    }
}