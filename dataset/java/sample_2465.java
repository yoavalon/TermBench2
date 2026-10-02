import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2465 {

    public static List<Integer> process_sequence(String text) {
        List<Integer> sequence = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        
        while (matcher.find()) {
            String token = matcher.group();
            if (token.matches("\\d+")) {
                sequence.add(Integer.parseInt(token));
            }
            if (sequence.size() == 10) {
                break;
            }
        }
        
        return sequence;
    }

    public static void main(String[] args) {
        String data = "The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10.";
        List<Integer> result = process_sequence(data);
        System.out.println(result);
    }
}