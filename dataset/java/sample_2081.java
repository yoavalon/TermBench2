import java.util.regex.*;
import java.util.*;

public class sample_2081 {
    public static List<String> tokenize(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static List<Object> process_tokens(List<String> tokens) {
        List<Object> processed = new ArrayList<>();
        for (String token : tokens) {
            if (token.matches("\\d+")) {
                processed.add(Integer.parseInt(token));
            } else if (token.matches("\\d+\\.\\d+")) {
                processed.add(Float.parseFloat(token));
            } else {
                processed.add(token);
            }
        }
        return processed;
    }

    public static Map<String, Integer> analyze_data(List<Object> data) {
        Map<String, Integer> stats = new HashMap<>();
        stats.put("integers", 0);
        stats.put("floats", 0);
        stats.put("words", 0);
        for (Object item : data) {
            if (item instanceof Integer) {
                stats.put("integers", stats.get("integers") + 1);
            } else if (item instanceof Float) {
                stats.put("floats", stats.get("floats") + 1);
            } else {
                stats.put("words", stats.get("words") + 1);
            }
        }
        return stats;
    }

    public static void main(String[] args) {
        String text = "The value of pi is approximately 3.14159. The number 42 is also interesting.";
        List<String> tokens = tokenize(text);
        List<Object> processed_data = process_tokens(tokens);
        Map<String, Integer> analysis = analyze_data(processed_data);
        System.out.println(analysis);
    }
}