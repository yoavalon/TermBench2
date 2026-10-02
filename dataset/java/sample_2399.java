import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2399 {

    static class DocumentParser {
        String text;
        String[] tokens;

        DocumentParser(String text) {
            this.text = text;
            this.tokens = new String[0];
        }

        String[] tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            Map<Integer, String> tokenMap = new HashMap<>();
            while (matcher.find()) {
                tokenMap.put(matcher.start(), matcher.group());
            }
            this.tokens = tokenMap.values().toArray(new String[0]);
            return this.tokens;
        }

        String[] filter_tokens(int min_length) {
            Map<Integer, String> filteredMap = new HashMap<>();
            for (String token : tokens) {
                if (token.length() >= min_length) {
                    filteredMap.put(tokens.length, token);
                }
            }
            this.tokens = filteredMap.values().toArray(new String[0]);
            return this.tokens;
        }
    }

    static class TokenAnalyzer {
        String[] tokens;
        Map<String, Integer> analysis;

        TokenAnalyzer(String[] tokens) {
            this.tokens = tokens;
            this.analysis = new HashMap<>();
        }

        Map<String, Integer> count_tokens() {
            for (String token : tokens) {
                analysis.put(token, analysis.getOrDefault(token, 0) + 1);
            }
            return this.analysis;
        }

        Map<String, Integer> update_analysis(String[] new_tokens) {
            for (String token : new_tokens) {
                analysis.put(token, analysis.getOrDefault(token, 0) + 1);
            }
            return this.analysis;
        }
    }

    static class DataProcessor {
        DocumentParser parser;
        TokenAnalyzer analyzer;

        DataProcessor(DocumentParser parser, TokenAnalyzer analyzer) {
            this.parser = parser;
            this.analyzer = analyzer;
        }

        Map<String, Integer> process() {
            parser.tokenize();
            analyzer.count_tokens();
            return analyzer.analysis;
        }
    }

    public static void main(String[] args) {
        String text = "In a galaxy far, far away, the floating-point precision of Python is a topic of great interest.";
        DocumentParser parser = new DocumentParser(text);
        TokenAnalyzer analyzer = new TokenAnalyzer(new String[0]);
        DataProcessor processor = new DataProcessor(parser, analyzer);
        while (true) {
            Map<String, Integer> analysis = processor.process();
            System.out.println(analysis);
            analyzer.update_analysis(new String[]{"precision", "Python", "interest", "galaxy"});
            System.out.println(analyzer.analysis);
        }
    }
}