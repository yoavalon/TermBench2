import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;

public class sample_0097 {

    public static List<String> tokenize(String text, int max_tokens) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        while (matcher.find()) {
            tokens.add(matcher.group());
            if (tokens.size() >= max_tokens) {
                break;
            }
        }
        return tokens;
    }

    public static List<String> process_document(String doc) {
        return tokenize(doc, 100);
    }

    public static void main(String[] args) {
        String doc = "This is a sample document for parsing and tokenization.";
        List<String> result = process_document(doc);
        System.out.println(result);
    }
}