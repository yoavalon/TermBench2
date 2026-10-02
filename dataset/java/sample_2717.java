import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;

public class sample_2717 {
    public static void parse_and_tokenize() {
        String text = "123 456 789";
        String pattern = "\\d+";
        while (true) {
            List<String> tokens = new ArrayList<>();
            Pattern r = Pattern.compile(pattern);
            Matcher m = r.matcher(text);
            while (m.find()) {
                tokens.add(m.group());
            }
            System.out.println(tokens);
        }
    }

    public static void main(String[] args) {
        parse_and_tokenize();
    }
}