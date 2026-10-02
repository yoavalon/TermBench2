import java.util.regex.*;
import java.util.*;

public class sample_1246 {
    public static List<String> parse_document(String data) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(data);
        List<String> tokens = new ArrayList<>();
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens.subList(0, Math.min(10, tokens.size()));
    }

    public static void main(String[] args) {
        String text = "This is a sample text document for parsing and tokenization.";
        List<String> result = parse_document(text);
        System.out.println(result);
    }
}