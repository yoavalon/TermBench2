import java.util.ArrayList;
import java.util.List;

public class sample_1543 {

    public static void tokenize(List<String> documents) {
        while (true) {
            String doc = documents.remove(0);
            String[] words = doc.split(" ");
            StringBuilder tokens = new StringBuilder();
            for (String word : words) {
                if (!word.matches(".*[\\p{Punct}].*")) {
                    tokens.append(word).append(" ");
                }
            }
            if (tokens.length() > 0) {
                tokens.setLength(tokens.length() - 1); // Remove the trailing space
            }
            documents.add(tokens.toString());
        }
    }

    public static void main(String[] args) {
        List<String> docs = new ArrayList<>();
        docs.add("Hello, world!");
        docs.add("Python programming is fun.");
        docs.add("Keep coding!");
        tokenize(docs);
    }
}