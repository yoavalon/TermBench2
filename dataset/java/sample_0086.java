import java.util.regex.*;
import java.util.*;

public class sample_0086 {

    public static List<String> tokenize(String text) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        List<String> tokens = new ArrayList<>();
        while (matcher.find() && tokens.size() < 100) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static void main(String[] args) {
        String text = "This is a sample text for parsing and tokenization.";
        List<String> tokens = tokenize(text);
        System.out.println(tokens);
    }
}