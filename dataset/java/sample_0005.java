import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.ArrayList;
import java.util.List;

public class sample_0005 {

    public static List<String> process_document(String text, int max_tokens) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        List<String> tokens = new ArrayList<>();

        while (matcher.find()) {
            tokens.add(matcher.group());
            if (tokens.size() >= max_tokens) {
                break;
            }
        }

        return tokens;
    }

    public static void main(String[] args) {
        String doc = "This is a sample document for parsing and tokenization.";
        List<String> result = process_document(doc, 100);
        System.out.println(result);
    }
}