import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1891 {
    public static List<String> analyze_text(String data) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(data);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        
        List<String> float_tokens = new ArrayList<>();
        Pattern floatPattern = Pattern.compile("^\\d+\\.\\d+$");
        for (String token : tokens) {
            if (floatPattern.matcher(token).matches()) {
                float_tokens.add(token);
            }
        }
        return float_tokens;
    }

    public static void main(String[] args) {
        String text = "The value of pi is approximately 3.14159. The number e is roughly 2.71828.";
        List<String> result = analyze_text(text);
        System.out.println(result);
    }
}