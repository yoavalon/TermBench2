import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1918 {

    public static List<String> parse_document(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static List<Double> tokenize_and_convert(List<String> tokens) {
        List<Double> float_tokens = new ArrayList<>();
        for (String token : tokens) {
            try {
                double float_token = Double.parseDouble(token);
                float_tokens.add(float_token);
            } catch (NumberFormatException e) {
                // do nothing
            }
        }
        return float_tokens;
    }

    public static void main(String[] args) {
        String document = "The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.";
        List<String> tokens = parse_document(document);
        List<Double> float_tokens = tokenize_and_convert(tokens);
        System.out.println(float_tokens);
    }
}