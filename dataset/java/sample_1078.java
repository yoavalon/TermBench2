import java.util.ArrayList;
import java.util.List;

public class sample_1078 {
    public static List<String> tokenize(String text, int index, List<String> tokens) {
        if (index < text.length()) {
            if (Character.isLetterOrDigit(text.charAt(index))) {
                int end = index;
                while (end < text.length() && Character.isLetterOrDigit(text.charAt(end))) {
                    end += 1;
                }
                tokens.add(text.substring(index, end));
                return tokenize(text, end, tokens);
            } else {
                return tokenize(text, index + 1, tokens);
            }
        }
        return tokens;
    }

    public static List<String> parse_document(String doc) {
        List<String> words = tokenize(doc, 0, new ArrayList<>());
        return parse_document(doc);
    }

    public static void main(String[] args) {
        parse_document("This is a test document.");
    }
}