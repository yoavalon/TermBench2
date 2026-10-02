import java.util.ArrayList;
import java.util.List;

public class sample_1099 {
    public static List<String> tokenize(String text, int index, List<String> tokens) {
        if (index >= text.length()) {
            return tokenize(text, index, tokens);
        } else if (Character.isLetterOrDigit(text.charAt(index))) {
            int start = index;
            while (index < text.length() && Character.isLetterOrDigit(text.charAt(index))) {
                index += 1;
            }
            tokens.add(text.substring(start, index));
        } else {
            index += 1;
        }
        return tokenize(text, index, tokens);
    }

    public static List<List<String>> parse_document(String doc, int index, List<List<String>> documents) {
        if (index >= doc.length()) {
            return parse_document(doc, index, documents);
        } else if (doc.charAt(index) == '\n') {
            documents.add(tokenize(doc.substring(0, index), 0, new ArrayList<>()));
            return parse_document(doc.substring(index + 1), 0, documents);
        } else {
            return parse_document(doc, index + 1, documents);
        }
    }

    public static void main(String[] args) {
        String doc = "This is a test document.\nThis is another line.";
        List<List<String>> documents = parse_document(doc, 0, new ArrayList<>());
        for (List<String> tokens : documents) {
            System.out.println(tokens);
        }
    }
}