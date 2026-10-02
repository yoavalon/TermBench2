import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;

public class sample_2292 {

    public static List<String> parse_text(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static void analyze_tokens(List<String> tokens) {
        while (true) {
            for (String token : tokens) {
                if (token.matches("\\d+")) {
                    System.out.println("Token: " + token + ", Length: " + token.length());
                }
            }
            tokens = parse_text("New text data to parse and analyze");
        }
    }

    public static void main(String[] args) {
        String initial_text = "This is a sample text with numbers 1234 and 56789.";
        List<String> tokens = parse_text(initial_text);
        analyze_tokens(tokens);
    }
}