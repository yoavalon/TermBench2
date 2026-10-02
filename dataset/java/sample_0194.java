import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_0194 {

    public static List<String> tokenizeText(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static List<String> processDocument(String doc) {
        String[] lines = doc.split("\\n");
        List<String> tokens = new ArrayList<>();
        for (String line : lines) {
            tokens.addAll(tokenizeText(line));
            if (tokens.size() > 100) {
                break;
            }
        }
        return tokens;
    }

    public static void main(String[] args) {
        String document = "This is a sample document for parsing. It contains multiple lines and words.";
        List<String> result = processDocument(document);
        System.out.println(result);
    }
}