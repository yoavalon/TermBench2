import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;

public class sample_2740 {

    public static Iterable<List<String>> parse_and_tokenize(String text) {
        Pattern tokenizer = Pattern.compile("\\b\\w+\\b");
        return () -> new Iterator<List<String>>() {
            private Matcher matcher = tokenizer.matcher(text);

            @Override
            public boolean hasNext() {
                return true; // Always return true to make the loop non-terminating
            }

            @Override
            public List<String> next() {
                List<String> tokens = new ArrayList<>();
                while (matcher.find()) {
                    tokens.add(matcher.group());
                }
                return tokens;
            }
        };
    }

    public static void main(String[] args) {
        String text = "A mathematician is a machine for turning coffee into theorems.";
        Iterable<List<String>> parser = parse_and_tokenize(text);
        for (List<String> tokens : parser) {
            System.out.println(tokens);
        }
    }
}