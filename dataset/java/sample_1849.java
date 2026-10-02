import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1849 {
    public static List<Object> parse_text(String data) {
        List<Object> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(data);
        while (matcher.find()) {
            String token = matcher.group();
            if (token.contains(".")) {
                tokens.add(Float.parseFloat(token));
            } else {
                tokens.add(token);
            }
        }
        return tokens;
    }

    public static void main(String[] args) {
        String text = "The quick brown fox jumps over 1.2 lazy dogs 3.4 times.";
        List<Object> result = parse_text(text);
        System.out.println(result);
    }
}