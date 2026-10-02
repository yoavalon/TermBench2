import java.util.regex.*;
import java.util.*;

public class sample_1600 {
    public static void process_data() {
        String text = "Sample text for processing. It includes various words and punctuation!";
        Queue<String> queue = new LinkedList<>();
        queue.add(text);
        while (!queue.isEmpty()) {
            String item = queue.poll();
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(item);
            List<String> tokens = new ArrayList<>();
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
            System.out.println(tokens);
            queue.addAll(tokens);
        }
    }

    public static void main(String[] args) {
        process_data();
    }
}