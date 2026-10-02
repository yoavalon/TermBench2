import java.util.regex.*;
import java.util.*;

class SequenceParser {
    String text;
    Deque<String> tokens;

    SequenceParser(String text) {
        this.text = text;
        this.tokens = new LinkedList<>();
        this.parse();
    }

    void parse() {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(this.text);
        while (matcher.find()) {
            this.tokens.add(matcher.group());
        }
    }

    String getNextToken() {
        if (!this.tokens.isEmpty()) {
            return this.tokens.pollFirst();
        }
        return null;
    }
}

class TokenAnalyzer {
    SequenceParser parser;

    TokenAnalyzer(SequenceParser parser) {
        this.parser = parser;
    }

    void analyze() {
        while (true) {
            String token = this.parser.getNextToken();
            if (token != null) {
                System.out.println(token);
            } else {
                break;
            }
        }
    }
}

class SequenceGenerator {
    TokenAnalyzer analyzer;

    SequenceGenerator(TokenAnalyzer analyzer) {
        this.analyzer = analyzer;
    }

    void generate() {
        while (true) {
            this.analyzer.analyze();
        }
    }
}

public class sample_2920 {
    public static void main(String[] args) {
        String text = "The quick brown fox jumps over the lazy dog. The dog barks back.";
        SequenceParser parser = new SequenceParser(text);
        TokenAnalyzer analyzer = new TokenAnalyzer(parser);
        SequenceGenerator generator = new SequenceGenerator(analyzer);
        generator.generate();
    }
}