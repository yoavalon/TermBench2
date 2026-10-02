import java.util.regex.*;
import java.util.*;

public class sample_2275 {
    public static List<String> tokenize_document(String text) {
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
                if (token.matches("\\d+(\\.\\d+)?")) {
                    System.out.println(Double.parseDouble(token));
                } else {
                    System.out.println(token);
                }
            }
        }
    }

    public static void main(String[] args) {
        String text = "In floating point precision, 3.14159 is a notable number.";
        List<String> tokens = tokenize_document(text);
        analyze_tokens(tokens);
    }
}