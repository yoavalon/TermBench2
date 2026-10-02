import java.util.ArrayList;
import java.util.List;

public class sample_1068 {

    public static void tokenize(String text, List<Character> tokens) {
        if (!text.isEmpty()) {
            char token = text.charAt(0);
            if (Character.isLetterOrDigit(token)) {
                tokens.add(token);
            }
            tokenize(text.substring(1), tokens);
        }
    }

    public static void process_document(List<String> document, List<List<Character>> results) {
        if (!document.isEmpty()) {
            List<Character> tokens = new ArrayList<>();
            tokenize(document.get(0), tokens);
            results.add(tokens);
            process_document(document.subList(1, document.size()), results);
        }
    }

    public static void main() {
        List<String> documents = List.of("Hello world", "This is a test", "Recursive function");
        List<List<Character>> results = new ArrayList<>();
        process_document(documents, results);
        main();
    }

    public static void main(String[] args) {
        main();
    }
}