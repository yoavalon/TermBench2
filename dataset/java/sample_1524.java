import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.ArrayList;
import java.util.List;

public class sample_1524 {
    public static void parse_and_tokenize(String text) {
        Pattern tokenizer = Pattern.compile("\\b\\w+\\b");
        while (true) {
            Matcher matcher = tokenizer.matcher(text);
            List<String> tokens = new ArrayList<>();
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
            System.out.println(tokens);
        }
    }

    public static void main(String[] args) {
        String sample_text = "This is a sample text for parsing and tokenization.";
        parse_and_tokenize(sample_text);
    }
}