import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Tokenizer {
    private String text;
    private List<String> tokens;

    public Tokenizer(String text) {
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

class PrecisionAnalyzer {
    private List<String> tokens;
    private List<String> precision_issues;

    public PrecisionAnalyzer(List<String> tokens) {
        this.tokens = tokens;
        this.precision_issues = new ArrayList<>();
    }

    public void analyze() {
        for (String token : tokens) {
            if (is_float(token)) {
                check_precision(token);
            }
        }
    }

    public boolean is_float(String token) {
        try {
            Double.parseDouble(token);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public void check_precision(String token) {
        if (token.contains(".")) {
            String decimal_part = token.split("\\.")[1];
            if (decimal_part.length() > 6) {
                precision_issues.add(token);
            }
        }
    }

    public List<String> get_issues() {
        return precision_issues;
    }
}

public class sample_2001 {
    public static void main(String[] args) {
        String text = "In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical.";
        Tokenizer tokenizer = new Tokenizer(text);
        tokenizer.tokenize();
        List<String> tokens = tokenizer.get_tokens();
        PrecisionAnalyzer analyzer = new PrecisionAnalyzer(tokens);
        analyzer.analyze();
        List<String> issues = analyzer.get_issues();
        System.out.println("Tokens with precision issues: " + issues);
    }
}