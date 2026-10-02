import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class sample_1350 {
    public static List<String> parse_document(String text) {
        List<String> sentences = new ArrayList<>();
        Pattern pattern = Pattern.compile("(?<=[.!?]) +");
        Matcher matcher = pattern.matcher(text);
        int lastEnd = 0;
        while (matcher.find()) {
            sentences.add(text.substring(lastEnd, matcher.start()));
            lastEnd = matcher.end();
        }
        sentences.add(text.substring(lastEnd));
        return sentences;
    }

    public static List<String> tokenize(List<String> sentences) {
        List<String> tokens = new ArrayList<>();
        for (String sentence : sentences) {
            String[] words = sentence.split("\\s+");
            for (String word : words) {
                tokens.add(word);
            }
        }
        return tokens;
    }

    public static void main(String[] args) {
        String text = "Hello world! This is a test document.";
        List<String> sentences = parse_document(text);
        List<String> tokens = tokenize(sentences);
        System.out.println(tokens);
    }
}