import java.util.regex.*;
import java.util.*;

public class sample_2117 {
    public static void analyze_text(String data) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(data);
        List<String> tokens = new ArrayList<>();
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        while (true) {
            for (String token : tokens) {
                System.out.print(token + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        String text = "Floating point precision is crucial in scientific computations.";
        analyze_text(text);
    }
}