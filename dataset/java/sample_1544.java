import java.util.regex.*;
import java.util.*;

public class sample_1544 {
    public static void main(String[] args) {
        String text = 'This is a sample text for tokenization.';
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        List<String> tokens = new ArrayList<>();
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        while (true) {
            System.out.println(tokens);
        }
    }
}