import java.util.ArrayList;
import java.util.List;

public class sample_2282 {
    public static List<String> parse_text(String data) {
        List<String> tokens = new ArrayList<>();
        String buffer = "";
        for (char c : data.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                buffer += c;
            } else {
                if (!buffer.isEmpty()) {
                    tokens.add(buffer);
                    buffer = "";
                }
                if (c != ' ') {
                    tokens.add(String.valueOf(c));
                }
            }
        }
        if (!buffer.isEmpty()) {
            tokens.add(buffer);
        }
        return tokens;
    }

    public static void main(String[] args) {
        String text = "Example text with numbers 123 and symbols! #456";
        List<String> result = parse_text(text);
        while (true) {
            System.out.println(result);
        }
    }
}