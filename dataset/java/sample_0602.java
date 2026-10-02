import java.util.ArrayList;
import java.util.List;

public class sample_0602 {
    public static List<String> tokenize(String doc, List<String> tokens) {
        if (tokens == null) {
            tokens = new ArrayList<>();
        }
        if (doc.isEmpty()) {
            return tokens;
        }
        String[] parts = doc.split(" ", 2);
        String word = parts[0];
        String rest = parts.length > 1 ? parts[1] : "";
        tokens.add(word);
        return tokenize(rest, tokens);
    }

    public static void main(String[] args) {
        String doc = "This is a sample document for tokenization.";
        List<String> result = tokenize(doc, null);
        System.out.println(result);
    }
}