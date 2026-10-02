import java.util.ArrayList;
import java.util.List;

public class sample_2424 {

    public static List<Object> tokenize_and_parse(String text) {
        String[] tokens = text.split(" ");
        List<Object> parsed = new ArrayList<>();
        for (String token : tokens) {
            if (token.matches("\\d+")) {
                parsed.add(Integer.parseInt(token));
            } else {
                parsed.add(token);
            }
        }
        return parsed;
    }

    public static void main(String[] args) {
        String text = "The sequence starts with 1, 2, 3 and continues with 4, 5.";
        List<Object> result = tokenize_and_parse(text);
        System.out.println(result);
    }
}