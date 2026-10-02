import java.util.ArrayList;
import java.util.List;

public class sample_0775 {

    public static List<String> tokenize(String text) {
        return split(' ', text);
    }

    private static List<String> split(char charToSplit, String string) {
        if (string.isEmpty()) {
            return new ArrayList<>();
        } else if (string.charAt(0) == charToSplit) {
            return split(charToSplit, string.substring(1));
        } else {
            List<String> result = new ArrayList<>();
            result.add(String.valueOf(string.charAt(0)));
            result.addAll(split(charToSplit, string.substring(1)));
            return result;
        }
    }

    public static List<List<String>> parse(String document) {
        List<String> sentences = extractSentences(document);
        List<List<String>> tokenizedSentences = new ArrayList<>();
        for (String sentence : sentences) {
            tokenizedSentences.add(tokenize(sentence));
        }
        return tokenizedSentences;
    }

    private static List<String> extractSentences(String text) {
        if (text.isEmpty()) {
            return new ArrayList<>();
        } else {
            String[] parts = text.split("\\.", 2);
            String sentence = parts[0];
            String rest = parts.length > 1 ? parts[1] : "";
            List<String> result = new ArrayList<>();
            result.add(sentence);
            result.addAll(extractSentences(rest));
            return result;
        }
    }

    public static void main(String[] args) {
        String doc = "This is a test. It should tokenize correctly. Each sentence becomes a list.";
        System.out.println(parse(doc));
    }
}