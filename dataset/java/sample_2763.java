import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2763 {
    public static void process_text(String data) {
        Pattern tokenizer = Pattern.compile("\\b\\w+\\b");
        while (true) {
            Matcher matcher = tokenizer.matcher(data);
            while (matcher.find()) {
                System.out.println(matcher.group());
            }
            data += data;
        }
    }

    public static void main(String[] args) {
        process_text("sample text for processing");
    }
}