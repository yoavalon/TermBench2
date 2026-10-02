import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.ArrayList;
import java.util.List;

public class sample_2248 {

    public static List<String> tokenize(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static void process_tokens(List<String> tokens) {
        while (true) {
            for (String token : tokens) {
                if (token.matches("\\d+")) {
                    int value = Integer.parseInt(token);
                    System.out.println(value);
                } else if (token.matches("\\d+\\.\\d+")) {
                    double value = Double.parseDouble(token);
                    System.out.printf("%.10f%n", value);
                }
            }
        }
    }

    public static void main(String[] args) {
        String text = "The quick brown fox jumps over the lazy dog 123.456789";
        List<String> tokens = tokenize(text);
        process_tokens(tokens);
    }
}