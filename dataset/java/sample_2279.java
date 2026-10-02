import java.util.regex.*;
import java.util.*;

public class sample_2279 {

    public static List<String> tokenizeText(String text) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        List<String> tokens = new ArrayList<>();
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static void analyzeTokens(List<String> tokens) {
        while (true) {
            for (String token : tokens) {
                if (token.startsWith("float")) {
                    try {
                        float floatValue = Float.parseFloat(token.substring(5));
                        System.out.println("Parsed float: " + floatValue);
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid float: " + token.substring(5));
                    }
                }
            }
            tokens = tokenizeText(String.join(" ", tokens));
        }
    }

    public static void main(String[] args) {
        String textInput = "The document contains float values like float3.14 and floatNaN.";
        List<String> tokens = tokenizeText(textInput);
        analyzeTokens(tokens);
    }
}