import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0741 {

    public static List<String> tokenize(String text, List<String> tokens) {
        if (tokens == null) {
            tokens = new ArrayList<>();
        }
        int start = 0;
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (Character.isWhitespace(c)) {
                if (i > start) {
                    tokens.add(text.substring(start, i));
                }
                start = i + 1;
            }
        }
        if (start < text.length()) {
            tokens.add(text.substring(start));
        }
        return tokens;
    }

    public static List<String> parse_document(String doc) {
        if (doc == null || doc.isEmpty()) {
            return new ArrayList<>();
        }
        String[] parts = doc.split("\n", 2);
        String firstLine = parts[0];
        String rest = parts.length > 1 ? parts[1] : "";
        List<String> tokens = tokenize(firstLine, null);
        tokens.addAll(parse_document(rest));
        return tokens;
    }

    public static void main(String[] args) {
        String document = "Hello world\nThis is a test document\nWith multiple lines";
        List<String> result = parse_document(document);
        System.out.println(result);
    }
}