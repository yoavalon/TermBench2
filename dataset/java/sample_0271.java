import java.util.regex.*;
import java.util.HashMap;
import java.util.Map;

public class sample_0271 {

    static class DocumentParser {

        String text;
        String[] tokens;

        DocumentParser(String text) {
            this.text = text;
            this.tokens = new String[0];
        }

        void preprocess_text() {
            this.text = this.text.toLowerCase();
            this.text = this.text.replaceAll("\\s+", " ");
            this.text = this.text.replaceAll("[^\\w\\s]", "");
        }

        void tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(this.text);
            int count = 0;
            while (matcher.find()) {
                count++;
            }
            this.tokens = new String[count];
            matcher.reset();
            int index = 0;
            while (matcher.find()) {
                this.tokens[index++] = matcher.group();
            }
        }
    }

    static class TokenAnalyzer {

        String[] tokens;
        Map<String, Integer> frequency;

        TokenAnalyzer(String[] tokens) {
            this.tokens = tokens;
            this.frequency = new HashMap<>();
        }

        void analyze_frequency() {
            for (String token : this.tokens) {
                if (this.frequency.containsKey(token)) {
                    this.frequency.put(token, this.frequency.get(token) + 1);
                } else {
                    this.frequency.put(token, 1);
                }
            }
        }
    }

    public static void main(String[] args) {
        String text_data = "Example document text for parsing and tokenization. This is a simple example.";
        DocumentParser parser = new DocumentParser(text_data);
        parser.preprocess_text();
        parser.tokenize();
        TokenAnalyzer analyzer = new TokenAnalyzer(parser.tokens);
        analyzer.analyze_frequency();
        for (Map.Entry<String, Integer> entry : analyzer.frequency.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}