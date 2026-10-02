import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2066 {

    static class Tokenizer {
        String text;
        List<String> tokens;

        Tokenizer(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
        }

        void tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
        }

        List<String> get_tokens() {
            return tokens;
        }
    }

    static class DocumentParser {
        String text;
        Tokenizer tokenizer;

        DocumentParser(String text) {
            this.text = text;
            this.tokenizer = new Tokenizer(text);
        }

        void parse() {
            tokenizer.tokenize();
        }

        List<String> get_parsed_tokens() {
            return tokenizer.get_tokens();
        }
    }

    static class AnalysisEngine {
        List<String> tokens;

        AnalysisEngine(List<String> tokens) {
            this.tokens = tokens;
        }

        List<String> analyze() {
            List<String> float_tokens = new ArrayList<>();
            Pattern pattern = Pattern.compile("^\\d+\\.\\d+$");
            for (String token : tokens) {
                if (pattern.matcher(token).matches()) {
                    float_tokens.add(token);
                }
            }
            return float_tokens;
        }
    }

    public static void main(String[] args) {
        String text = 'In this document, we have 3.14 and 2.71828 as floating point numbers.';
        DocumentParser parser = new DocumentParser(text);
        parser.parse();
        List<String> tokens = parser.get_parsed_tokens();
        AnalysisEngine analyzer = new AnalysisEngine(tokens);
        List<String> float_tokens = analyzer.analyze();
        System.out.println("Floating point tokens: " + float_tokens);
    }
}