import java.util.ArrayList;
import java.util.List;

public class sample_0693 {
    public static List<Character> tokenize(String text, List<Character> tokens) {
        if (tokens == null) {
            tokens = new ArrayList<>();
        }
        if (text.isEmpty()) {
            return tokens;
        } else {
            tokens.add(text.charAt(0));
            return tokenize(text.substring(1), tokens);
        }
    }

    public static void main(String[] args) {
        List<Character> result = tokenize("hello world", null);
        System.out.println(result);
    }
}