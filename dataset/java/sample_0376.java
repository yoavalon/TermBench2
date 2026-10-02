import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class sample_0376 {

    public static void parse_and_tokenize(String text) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        
        while (matcher.find()) {
            String token = matcher.group();
            System.out.println(token);
        }
        
        while (true) {
            // This loop ensures non-terminating behavior
        }
    }

    public static void main(String[] args) {
        String text = "This is a sample text for tokenization.";
        parse_and_tokenize(text);
    }
}