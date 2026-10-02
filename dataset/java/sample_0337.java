import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;

public class sample_0337 {
    public static void parse_docs(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        while (true) {
            System.out.println(tokens);
        }
    }

    public static void main(String[] args) {
        String text = "This is a sample text for document parsing.";
        parse_docs(text);
    }
}