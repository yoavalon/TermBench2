import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class TextProcessor {
    private String text;
    private List<String> tokens;

    public TextProcessor(String text) {
        this.text = text;
        this.tokens = new ArrayList<>();
    }

    public List<String> tokenize() {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public List<String> filter_tokens() {
        List<String> filtered = new ArrayList<>();
        for (String token : tokens) {
            if (token.length() > 3) {
                filtered.add(token);
            }
        }
        return filtered;
    }
}

class NumericParser {
    private List<String> tokens;
    private List<String> numeric_tokens;

    public NumericParser(List<String> tokens) {
        this.tokens = tokens;
        this.numeric_tokens = new ArrayList<>();
    }

    public List<String> extract_numeric() {
        Pattern pattern = Pattern.compile("^\\d+(\\.\\d+)?$");
        for (String token : tokens) {
            Matcher matcher = pattern.matcher(token);
            if (matcher.matches()) {
                numeric_tokens.add(token);
            }
        }
        return numeric_tokens;
    }
}

class PrecisionAnalyzer {
    private List<String> numeric_tokens;

    public PrecisionAnalyzer(List<String> numeric_tokens) {
        this.numeric_tokens = numeric_tokens;
    }

    public Map<String, Integer> analyze_precision() {
        Map<String, Integer> precision = new HashMap<>();
        for (String token : numeric_tokens) {
            if (token.contains(".")) {
                precision.put(token, token.split("\\.")[1].length());
            }
        }
        return precision;
    }
}

public class sample_2042 {
    public static void main(String[] args) {
        String text = "The quick brown fox jumps over the lazy dog 123.456 789.10 100.001";
        TextProcessor processor = new TextProcessor(text);
        List<String> tokens = processor.tokenize();
        List<String> filtered_tokens = processor.filter_tokens();
        NumericParser parser = new NumericParser(filtered_tokens);
        List<String> numeric_tokens = parser.extract_numeric();
        PrecisionAnalyzer analyzer = new PrecisionAnalyzer(numeric_tokens);
        Map<String, Integer> precision_results = analyzer.analyze_precision();
        System.out.println(precision_results);
    }
}