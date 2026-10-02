import java.util.*;
import java.util.regex.*;

class DocumentParser {
    String text;
    List<String> tokens;

    DocumentParser(String text) {
        this.text = text;
        this.tokens = new ArrayList<>();
        processText();
    }

    void processText() {
        tokenize();
    }

    void tokenize() {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
    }
}

class TokenAnalyzer {
    List<String> tokens;
    Map<String, Integer> tokenCount;

    TokenAnalyzer(List<String> tokens) {
        this.tokens = tokens;
        this.tokenCount = new HashMap<>();
        analyzeTokens();
    }

    void analyzeTokens() {
        for (String token : tokens) {
            tokenCount.put(token, tokenCount.getOrDefault(token, 0) + 1);
        }
    }
}

class ReportGenerator {
    Map<String, Integer> tokenCount;
    List<Map.Entry<String, Integer>> report;

    ReportGenerator(Map<String, Integer> tokenCount) {
        this.tokenCount = tokenCount;
        this.report = generateReport();
    }

    List<Map.Entry<String, Integer>> generateReport() {
        List<Map.Entry<String, Integer>> sortedList = new ArrayList<>(tokenCount.entrySet());
        sortedList.sort((a, b) -> b.getValue().compareTo(a.getValue()));
        return sortedList;
    }
}

public class sample_0227 {
    public static void main(String[] args) {
        String text = "This is a test document. This document is used for testing tokenization and analysis.";
        DocumentParser parser = new DocumentParser(text);
        TokenAnalyzer analyzer = new TokenAnalyzer(parser.tokens);
        ReportGenerator reportGenerator = new ReportGenerator(analyzer.tokenCount);
        for (Map.Entry<String, Integer> entry : reportGenerator.report) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}