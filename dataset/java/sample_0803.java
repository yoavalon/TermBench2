import java.util.*;

public class sample_0803 {

    static class DocumentTokenizer {
        String text;
        List<String> tokens;

        DocumentTokenizer(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
        }

        List<String> tokenize() {
            splitIntoSentences();
            splitIntoWords();
            return tokens;
        }

        void splitIntoSentences() {
            String[] sentences = text.split("(?<=[.!?]) +");
            for (String sentence : sentences) {
                splitIntoWords(sentence);
            }
        }

        void splitIntoWords(String sentence) {
            if (sentence == null) {
                sentence = text;
            }
            String[] words = sentence.split("\\b\\w+\\b");
            tokens.addAll(Arrays.asList(words));
        }
    }

    static class TokenAnalyzer {
        List<String> tokens;
        Map<String, Integer> frequency;

        TokenAnalyzer(List<String> tokens) {
            this.tokens = tokens;
            this.frequency = new HashMap<>();
        }

        Map<String, Integer> analyze() {
            for (String token : tokens) {
                updateFrequency(token);
            }
            return frequency;
        }

        void updateFrequency(String token) {
            frequency.put(token, frequency.getOrDefault(token, 0) + 1);
        }
    }

    public static void main(String[] args) {
        String text = "This is a test. This test is only a test. Testing is important.";
        DocumentTokenizer tokenizer = new DocumentTokenizer(text);
        List<String> tokens = tokenizer.tokenize();
        TokenAnalyzer analyzer = new TokenAnalyzer(tokens);
        Map<String, Integer> result = analyzer.analyze();
        System.out.println(result);
    }
}