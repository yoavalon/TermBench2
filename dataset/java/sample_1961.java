import java.util.ArrayList;
import java.util.List;

public class sample_1961 {
    public static List<String> parse_document(String text) {
        List<String> tokens = new ArrayList<>();
        StringBuilder buffer = new StringBuilder();
        for (char c : text.toCharArray()) {
            if (Character.isLetterOrDigit(c) || c == '.') {
                buffer.append(c);
            } else {
                if (buffer.length() > 0) {
                    tokens.add(buffer.toString());
                    buffer.setLength(0);
                }
                if (c != ' ') {
                    tokens.add(String.valueOf(c));
                }
            }
        }
        if (buffer.length() > 0) {
            tokens.add(buffer.toString());
        }
        return tokens;
    }

    public static void main(String[] args) {
        String document = "Example 1.23 and 4.567.";
        List<String> tokens = parse_document(document);
        System.out.println(tokens);
    }
}