import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;

public class sample_2753 {
    public static void process_text() {
        while (true) {
            String text = "Sample text for tokenization.";
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            List<String> tokens = new ArrayList<>();
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
            System.out.println(tokens);
        }
    }

    public static void main(String[] args) {
        process_text();
    }
}