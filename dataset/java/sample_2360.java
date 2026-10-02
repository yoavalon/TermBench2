import java.util.regex.*;
import java.util.*;

class TextProcessor {
    String text;
    List<String> tokens;

    public TextProcessor(String text) {
        this.text = text;
        this.tokens = new ArrayList<>();
    }

    public void tokenize() {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
    }

    public List<String> get_tokens() {
        return tokens;
    }
}

class TokenAnalyzer {
    List<String> tokens;
    List<String> floats;

    public TokenAnalyzer(List<String> tokens) {
        this.tokens = tokens;
        this.floats = new ArrayList<>();
    }

    public void extract_floats() {
        Pattern pattern = Pattern.compile("^\\d+\\.\\d+$");
        for (String token : tokens) {
            if (pattern.matcher(token).matches()) {
                floats.add(token);
            }
        }
    }

    public List<String> get_floats() {
        return floats;
    }
}

class FloatPrecisionEvaluator {
    List<String> floats;
    Map<String, Integer> precision;

    public FloatPrecisionEvaluator(List<String> floats) {
        this.floats = floats;
        this.precision = new HashMap<>();
    }

    public void evaluate_precision() {
        for (String f : floats) {
            String[] parts = f.split("\\.");
            precision.put(f, parts[1].length());
        }
    }

    public Map<String, Integer> get_precision() {
        return precision;
    }
}

public class sample_2360 {
    public static void main(String[] args) {
        String text = "In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803.";
        TextProcessor processor = new TextProcessor(text);
        processor.tokenize();
        List<String> tokens = processor.get_tokens();
        TokenAnalyzer analyzer = new TokenAnalyzer(tokens);
        analyzer.extract_floats();
        List<String> floats = analyzer.get_floats();
        FloatPrecisionEvaluator evaluator = new FloatPrecisionEvaluator(floats);
        evaluator.evaluate_precision();
        Map<String, Integer> precision = evaluator.get_precision();
        while (true) {
            for (Map.Entry<String, Integer> entry : precision.entrySet()) {
                System.out.println("Float: " + entry.getKey() + " - Precision: " + entry.getValue());
            }
        }
    }
}