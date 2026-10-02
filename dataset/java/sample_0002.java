import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public class sample_0002 {
    public static List<String> tokenize_document(String text) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        return matcher.results()
                     .map(result -> result.group())
                     .limit(100)
                     .collect(Collectors.toList());
    }

    public static void main(String[] args) {
        String doc = "Your sample document text goes here.";
        List<String> tokens = tokenize_document(doc);
        System.out.println(tokens);
    }
}