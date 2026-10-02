import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2434 {
    public static List<Integer> process_text(String data) {
        List<Integer> sequences = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(data);
        while (matcher.find()) {
            String token = matcher.group();
            if (token.matches("\\d+")) {
                sequences.add(Integer.parseInt(token));
            }
        }
        return sequences;
    }

    public static void main(String[] args) {
        String text = "The sequence starts at 1, then 2, 3, and so on until 10.";
        List<Integer> result = process_text(text);
        System.out.println(result);
    }
}