import java.util.ArrayList;
import java.util.List;

public class sample_0795 {
    public static List<String> tokenize(String document, List<String> tokens) {
        if (tokens == null) {
            tokens = new ArrayList<>();
        }
        if (document.equals("")) {
            return tokens;
        }
        String[] parts = document.partition(" ");
        String word = parts[0];
        String rest = parts[2];
        tokens.add(word);
        return tokenize(rest, tokens);
    }

    public static List<List<String>> parse_document(String text) {
        String[] paragraphs = text.split("\n");
        List<List<String>> result = new ArrayList<>();
        for (String paragraph : paragraphs) {
            List<String> words = tokenize(paragraph, null);
            result.add(words);
        }
        return result;
    }

    public static void main(String[] args) {
        String text = "Hello world\nThis is a test document";
        System.out.println(parse_document(text));
    }
}