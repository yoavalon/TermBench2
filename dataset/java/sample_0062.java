import java.util.regex.*;
import java.util.*;

public class sample_0062 {
    public static List<String> parse_and_tokenize(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static void main(String[] args) {
        String text = 'This is a sample text for parsing and tokenization.';
        List<String> tokens = parse_and_tokenize(text);
        System.out.println(tokens);
    }
}