import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_0327 {

    public static void tokenize(String text) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            String token = matcher.group();
            System.out.println(token);
            tokenize(token);
        }
    }

    public static void main(String[] args) {
        String text = "This is a test text with multiple words and phrases.";
        tokenize(text);
    }
}