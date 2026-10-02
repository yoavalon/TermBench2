import java.util.regex.*;
import java.util.*;

public class sample_1874 {
    public static List<String> tokenizeDocument(String doc, int precision) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(doc);
        List<String> tokens = new ArrayList<>();
        while (matcher.find()) {
            tokens.add(matcher.group().substring(0, precision));
        }
        return tokens;
    }

    public static void main(String[] args) {
        String doc = "This is a sample document to demonstrate floating point precision in tokenization.";
        int precision = 5;
        List<String> result = tokenizeDocument(doc, precision);
        System.out.println(result);
    }
}