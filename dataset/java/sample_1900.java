import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1900 {
    public static List<String> parse_text(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        List<String> float_tokens = new ArrayList<>();
        for (String token : tokens) {
            if (token.matches("^\\d+\\.\\d+$")) {
                float_tokens.add(token);
            }
        }
        return float_tokens;
    }

    public static void main(String[] args) {
        String text = "The value of pi is approximately 3.14159. The number 2.71828 is also important.";
        List<String> result = parse_text(text);
        System.out.println(result);
    }
}