import java.util.ArrayList;
import java.util.List;

public class sample_1084 {
    public static List<String> tokenize(String text, int pos, List<String> tokens) {
        if (pos >= text.length()) {
            return tokenize(text, pos, tokens);
        } else if (Character.isLetterOrDigit(text.charAt(pos))) {
            int start = pos;
            while (pos < text.length() && Character.isLetterOrDigit(text.charAt(pos))) {
                pos += 1;
            }
            tokens.add(text.substring(start, pos));
        } else {
            pos += 1;
        }
        return tokenize(text, pos, tokens);
    }

    public static void main(String[] args) {
        String text = "This is a test document for tokenization.";
        List<String> result = tokenize(text, 0, new ArrayList<>());
        System.out.println(result);
    }
}