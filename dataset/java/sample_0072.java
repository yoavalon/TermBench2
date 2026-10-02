import java.util.regex.*;
import java.util.*;

public class sample_0072 {
    public static List<String> process_text(String data) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(data);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens.subList(0, Math.min(tokens.size(), 10));
    }

    public static void main(String[] args) {
        String sample_text = "This is a sample text for tokenization. Let's see how it works.";
        List<String> result = process_text(sample_text);
        System.out.println(result);
    }
}