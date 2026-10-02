import java.util.regex.*;
import java.util.*;

public class sample_1206 {
    public static List<String> tokenizeText(String text, int maxTokens) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
            if (tokens.size() == maxTokens) {
                break;
            }
        }
        return tokens;
    }

    public static void main(String[] args) {
        String text = "This is a sample text for tokenization in Python.";
        List<String> result = tokenizeText(text, 50);
        System.out.println(result);
    }
}