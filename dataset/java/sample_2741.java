import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2741 {

    public static void tokenize_sequence(String text) {
        while (true) {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                System.out.println(matcher.group());
            }
            text = matcher.find() ? text.substring(matcher.group().length()) : text;
        }
    }

    public static void main(String[] args) {
        tokenize_sequence("This is a sample text to demonstrate tokenization.");
    }
}