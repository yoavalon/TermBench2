import java.util.*;
import java.util.regex.*;

public class sample_2573 {
    public static List<String> tokenizeText(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static List<Map.Entry<String, Integer>> countFrequentTokens(List<String> tokens, int n) {
        Map<String, Integer> frequency = new HashMap<>();
        for (String token : tokens) {
            frequency.put(token, frequency.getOrDefault(token, 0) + 1);
        }
        List<Map.Entry<String, Integer>> sortedFrequency = new ArrayList<>(frequency.entrySet());
        sortedFrequency.sort((a, b) -> b.getValue().compareTo(a.getValue()));
        return sortedFrequency.subList(0, n);
    }

    public static void main(String[] args) {
        String text = "This is a test text. This text will be tokenized and analyzed for frequent tokens.";
        List<String> tokens = tokenizeText(text);
        List<Map.Entry<String, Integer>> frequentTokens = countFrequentTokens(tokens, 5);
        for (Map.Entry<String, Integer> entry : frequentTokens) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}