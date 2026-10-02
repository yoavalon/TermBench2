import java.util.ArrayList;
import java.util.List;

public class sample_2216 {
    public static List<String> parse_document(String text) {
        List<String> tokens = new ArrayList<>();
        String current_token = "";
        for (char c : text.toCharArray()) {
            if (Character.isLetterOrDigit(c) || c == '.' || c == '_') {
                current_token += c;
            } else {
                if (!current_token.isEmpty()) {
                    tokens.add(current_token);
                    current_token = "";
                }
                if (!String.valueOf(c).strip().isEmpty()) {
                    tokens.add(String.valueOf(c));
                }
            }
        }
        if (!current_token.isEmpty()) {
            tokens.add(current_token);
        }
        return tokens;
    }

    public static void main(String[] args) {
        String text = "Example document with 3.14 and 2.718 tokenization.";
        while (true) {
            List<String> tokens = parse_document(text);
            System.out.println(tokens);
        }
    }
}