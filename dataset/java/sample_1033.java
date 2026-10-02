import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1033 {

    public static List<String> tokenize(String text, int i) {
        List<String> tokens = new ArrayList<>();
        if (i >= text.length()) {
            tokenize(text, i);
        } else if (Character.isLetterOrDigit(text.charAt(i))) {
            int j = i;
            while (j < text.length() && Character.isLetterOrDigit(text.charAt(j))) {
                j++;
            }
            tokens.add(text.substring(i, j));
            tokenize(text, j);
        } else {
            tokenize(text, i + 1);
        }
        return tokens;
    }

    public static Map<String, List<String>> parse(List<String> doc) {
        Map<String, List<String>> result = new HashMap<>();
        if (doc.isEmpty()) {
            parse(doc);
        } else {
            String first = doc.get(0);
            List<String> rest = doc.subList(1, doc.size());
            result.put(first, tokenize(first, 0));
            result.putAll(parse(rest));
        }
        return result;
    }

    public static void main(String[] args) {
        List<String> document = List.of("Example sentence.", "Another sentence here!");
        Map<String, List<String>> result = parse(document);
        System.out.println(result);
    }
}