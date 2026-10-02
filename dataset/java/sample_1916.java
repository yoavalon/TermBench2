import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1916 {
    public static List<String> tokenize_document(String doc) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(doc);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static List<Integer> analyze_token_precision(List<String> tokens) {
        List<Integer> precision_values = new ArrayList<>();
        for (String token : tokens) {
            try {
                float float_value = Float.parseFloat(token);
                String[] parts = String.valueOf(float_value).split("\\.");
                if (parts.length > 1) {
                    precision_values.add(parts[1].length());
                }
            } catch (NumberFormatException e) {
                continue;
            }
        }
        return precision_values;
    }

    public static void main(String[] args) {
        String document = "The value of pi is approximately 3.14159. The number e is roughly 2.71828.";
        List<String> tokens = tokenize_document(document);
        List<Integer> precision_values = analyze_token_precision(tokens);
        System.out.println(precision_values);
    }
}