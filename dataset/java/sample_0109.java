import java.util.regex.*;
import java.util.*;

public class sample_0109 {
    public static List<String> tokenize_document(String doc) {
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(doc);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static String[] analyze_boundaries(List<String> tokens) {
        String start = tokens.get(0);
        String end = tokens.get(tokens.size() - 1);
        return new String[]{start, end};
    }

    public static void main(String[] args) {
        String doc = "This is a sample document for tokenization and boundary analysis.";
        List<String> tokens = tokenize_document(doc);
        String[] boundaries = analyze_boundaries(tokens);
        System.out.println("Start: " + boundaries[0] + ", End: " + boundaries[1]);
    }
}