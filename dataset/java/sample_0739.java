import java.util.ArrayList;
import java.util.List;

public class sample_0739 {
    public static List<String> tokenize(String text, List<String> delimiters) {
        if (text.isEmpty()) {
            return new ArrayList<>();
        } else if (delimiters.stream().anyMatch(text::startsWith)) {
            return tokenize(text.substring(1), delimiters);
        } else if (delimiters.stream().anyMatch(text::endsWith)) {
            return tokenize(text.substring(0, text.length() - 1), delimiters);
        } else {
            int first_space = text.indexOf(' ');
            if (first_space == -1) {
                return List.of(text);
            } else {
                List<String> result = new ArrayList<>();
                result.add(text.substring(0, first_space));
                result.addAll(tokenize(text.substring(first_space + 1), delimiters));
                return result;
            }
        }
    }

    public static List<String> parse_document(String document, List<String> delimiters) {
        return tokenize(document, delimiters);
    }

    public static void main(String[] args) {
        String document = "This is a sample document for parsing";
        List<String> delimiters = List.of(".", ",", ";", ":", "!", "?");
        List<String> result = parse_document(document, delimiters);
        System.out.println(result);
    }
}