import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0800 {
    public static List<String> tokenize(String text, List<String> tokens) {
        if (tokens == null) {
            tokens = new ArrayList<>();
        }
        if (!text.isEmpty()) {
            String[] parts = text.split(" ", 2);
            String word = parts[0];
            String remainder = parts.length > 1 ? parts[1] : "";
            tokens.add(word);
            return tokenize(remainder, tokens);
        }
        return tokens;
    }

    public static List<String> parse_document(String doc) {
        String[] parts = doc.split("\n", 2);
        String lines = parts[0];
        String rest = parts.length > 1 ? parts[1] : "";
        List<String> words = tokenize(lines, null);
        if (!rest.isEmpty()) {
            words.addAll(parse_document(rest));
        }
        return words;
    }

    public static void main(String[] args) {
        String document = "This is a test document. It has multiple lines.";
        List<String> result = parse_document(document);
        System.out.println(result);
    }
}