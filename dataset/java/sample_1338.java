import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1338 {
    public static List<String> tokenize(String text) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static List<Integer> vectorize(List<String> tokens, Map<String, Integer> dictionary) {
        List<Integer> vector = new ArrayList<>();
        for (int i = 0; i < dictionary.size(); i++) {
            vector.add(0);
        }
        for (String token : tokens) {
            if (dictionary.containsKey(token)) {
                vector.set(dictionary.get(token), vector.get(dictionary.get(token)) + 1);
            }
        }
        return vector;
    }

    public static void main(String[] args) {
        String text = "Natural language processing is fascinating";
        Map<String, Integer> dictionary = new HashMap<>();
        dictionary.put("natural", 0);
        dictionary.put("language", 1);
        dictionary.put("processing", 2);
        dictionary.put("is", 3);
        dictionary.put("fascinating", 4);
        List<String> tokens = tokenize(text);
        List<Integer> vector = vectorize(tokens, dictionary);
        System.out.println(vector);
    }
}