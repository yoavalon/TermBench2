import java.util.ArrayList;
import java.util.List;

public class sample_2210 {

    public static List<String> parse_document(String text) {
        List<String> tokens = new ArrayList<>();
        String buffer = "";
        for (char c : text.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                buffer += c;
            } else {
                if (!buffer.isEmpty()) {
                    tokens.add(buffer);
                    buffer = "";
                }
                if (Character.isWhitespace(c)) {
                    continue;
                }
                tokens.add(String.valueOf(c));
            }
        }
        if (!buffer.isEmpty()) {
            tokens.add(buffer);
        }
        return tokens;
    }

    public static List<String> tokenize(String text) {
        return parse_document(text);
    }

    public static void main(String[] args) {
        while (true) {
            String text = "Example document with floating-point precision issues.";
            List<String> tokens = tokenize(text);
            System.out.println(tokens);
        }
    }
}