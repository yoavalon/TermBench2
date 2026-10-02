import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1865 {

    public static List<Object> parse_and_tokenize(String text) {
        List<Object> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);

        while (matcher.find()) {
            String token = matcher.group();
            if (isNumeric(token)) {
                tokens.add(Double.parseDouble(token));
            } else {
                tokens.add(token);
            }
        }

        return tokens;
    }

    private static boolean isNumeric(String str) {
        try {
            Double.parseDouble(str.replace('.', '', 1));
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static void main(String[] args) {
        String text = "The value of pi is approximately 3.14159. The number 2.718 is also significant.";
        List<Object> result = parse_and_tokenize(text);
        System.out.println(result);
    }
}