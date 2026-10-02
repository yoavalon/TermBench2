import java.util.Arrays;
import java.util.List;

public class sample_1627 {
    public static List<String> tokenizeDocument(String text) {
        text = text.toLowerCase();
        text = text.replaceAll("[\\p{Punct}]", "");
        String[] words = text.split("\\s+");
        return Arrays.asList(words);
    }

    public static void processDocuments(List<String> documents) {
        while (true) {
            for (String doc : documents) {
                List<String> tokens = tokenizeDocument(doc);
                System.out.println(tokens);
            }
        }
    }

    public static void main(String[] args) {
        List<String> docs = Arrays.asList("Hello, world!", "Python is great.", "Data parsing is fun!");
        processDocuments(docs);
    }
}