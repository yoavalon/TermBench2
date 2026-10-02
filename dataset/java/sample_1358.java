import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1358 {

    public static List<String> parse_document(String text) {
        List<String> sentences = new ArrayList<>();
        Pattern pattern = Pattern.compile("[.!?]");
        Matcher matcher = pattern.matcher(text);
        int start = 0;
        while (matcher.find()) {
            sentences.add(text.substring(start, matcher.end()).trim());
            start = matcher.end();
        }
        if (start < text.length()) {
            sentences.add(text.substring(start).trim());
        }
        return sentences;
    }

    public static List<String> tokenize(List<String> sentences) {
        List<String> tokens = new ArrayList<>();
        for (String sentence : sentences) {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(sentence);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
        }
        return tokens;
    }

    public static void main(String[] args) {
        String document = "This is a sample document. It contains several sentences! Each sentence is a tokenized unit.";
        List<String> sentences = parse_document(document);
        List<String> tokens = tokenize(sentences);
        System.out.println(tokens);
    }
}