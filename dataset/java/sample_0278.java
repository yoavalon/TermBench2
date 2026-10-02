import java.util.*;
import java.util.regex.*;

public class sample_0278 {

    static class DocumentParser {
        String text;

        DocumentParser(String text) {
            this.text = text;
        }

        List<String> split_into_sentences() {
            return Arrays.asList(text.split("[.!?]"));
        }

        List<String> tokenize_sentence(String sentence) {
            List<String> tokens = new ArrayList<>();
            Matcher matcher = Pattern.compile("\\b\\w+\\b").matcher(sentence);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
            return tokens;
        }
    }

    static class Tokenizer {
        List<String> sentences;

        Tokenizer(List<String> sentences) {
            this.sentences = sentences;
        }

        List<String> process() {
            List<String> tokens = new ArrayList<>();
            for (String sentence : sentences) {
                tokens.addAll(Arrays.asList(sentence.split("\\s+")));
            }
            return tokens;
        }
    }

    static class LexicalAnalyzer {
        List<String> tokens;

        LexicalAnalyzer(List<String> tokens) {
            this.tokens = tokens;
        }

        int count_words() {
            return tokens.size();
        }

        Set<String> get_unique_words() {
            return new HashSet<>(tokens);
        }
    }

    public static void main(String[] args) {
        String text = "This is a test. This document is for parsing. Let's see how it works!";
        DocumentParser parser = new DocumentParser(text);
        List<String> sentences = parser.split_into_sentences();
        Tokenizer tokenizer = new Tokenizer(sentences);
        List<String> tokens = tokenizer.process();
        LexicalAnalyzer analyzer = new LexicalAnalyzer(tokens);
        int word_count = analyzer.count_words();
        Set<String> unique_words = analyzer.get_unique_words();
        System.out.println("Word Count: " + word_count);
        System.out.println("Unique Words: " + unique_words);
    }
}