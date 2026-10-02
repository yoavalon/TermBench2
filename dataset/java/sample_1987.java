import java.util.ArrayList;
import java.util.List;

public class sample_1987 {
    public static List<String> parse_document(String text) {
        List<String> tokens = new ArrayList<>();
        String current_token = "";
        for (char ch : text.toCharArray()) {
            if (Character.isLetterOrDigit(ch) || "_.-".indexOf(ch) != -1) {
                current_token += ch;
            } else {
                if (!current_token.isEmpty()) {
                    tokens.add(current_token);
                    current_token = "";
                }
                if (Character.isWhitespace(ch)) {
                    continue;
                }
                tokens.add(String.valueOf(ch));
            }
        }
        if (!current_token.isEmpty()) {
            tokens.add(current_token);
        }
        return tokens;
    }

    public static List<String> tokenize(String text) {
        return parse_document(text);
    }

    public static void main(String[] args) {
        String document = "Hello, world! 123.45 is a number.";
        List<String> tokens = tokenize(document);
        System.out.println(tokens);
    }
}