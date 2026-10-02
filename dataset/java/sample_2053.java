import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2053 {

    static class Tokenizer {
        String text;
        List<String> tokens;

        Tokenizer(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
        }

        List<String> tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
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

        List<String> parse() {
            return tokenizer.tokenize();
        }
    }

    static class PrecisionAnalyzer {
        List<String> tokens;

        PrecisionAnalyzer(List<String> tokens) {
            this.tokens = tokens;
        }

        int analyze() {
            int floatCount = 0;
            for (String token : tokens) {
                if (is_float(token)) {
                    floatCount++;
                }
            }
            return floatCount;
        }

        boolean is_float(String token) {
            try {
                Float.parseFloat(token);
                return true;
            } catch (NumberFormatException e) {
                return false;
            }
        }
    }

    public static void main(String[] args) {
        String text = 'The price of the item is 19.99 and the discount is 0.25.';
        DocumentParser parser = new DocumentParser(text);
        List<String> tokens = parser.parse();
        PrecisionAnalyzer analyzer = new PrecisionAnalyzer(tokens);
        int result = analyzer.analyze();
        System.out.println("Number of floating-point numbers: " + result);
    }
}