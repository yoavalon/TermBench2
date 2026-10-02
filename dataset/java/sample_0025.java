import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;

public class sample_0025 {

    public static List<String> tokenizeDocument(String text, int maxTokens) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find() && tokens.size() < maxTokens) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static void main(String[] args) {
        String document = "This is a sample document for tokenization testing.";
        int maxTokens = 5;
        List<String> result = tokenizeDocument(document, maxTokens);
        System.out.println(result);
    }
}