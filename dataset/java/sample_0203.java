import java.util.*;
import java.util.regex.*;

class DocumentParser {
    String text;
    List<String> tokens;

    DocumentParser(String text) {
        this.text = text;
        this.tokens = new ArrayList<>();
    }

    void tokenize() {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text.toLowerCase());
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
    }

    void filter_tokens(int min_length) {
        List<String> filteredTokens = new ArrayList<>();
        for (String token : tokens) {
            if (token.length() > min_length) {
                filteredTokens.add(token);
            }
        }
        tokens = filteredTokens;
    }
}

class TokenAnalyzer {
    List<String> tokens;
    Map<String, Integer> freq_dict;

    TokenAnalyzer(List<String> tokens) {
        this.tokens = tokens;
        this.freq_dict = new HashMap<>();
    }

    void calculate_frequencies() {
        for (String token : tokens) {
            freq_dict.put(token, freq_dict.getOrDefault(token, 0) + 1);
        }
    }

    Map<String, Integer> get_top_frequencies(int n) {
        List<Map.Entry<String, Integer>> sortedList = new ArrayList<>(freq_dict.entrySet());
        sortedList.sort(Map.Entry.<String, Integer>comparingByValue().reversed());
        Map<String, Integer> topFrequencies = new LinkedHashMap<>();
        for (int i = 0; i < Math.min(n, sortedList.size()); i++) {
            topFrequencies.put(sortedList.get(i).getKey(), sortedList.get(i).getValue());
        }
        return topFrequencies;
    }
}

public class sample_0203 {
    public static void main(String[] args) {
        String sample_text = "This is a sample text for parsing and tokenization. Let's see how it works.";
        DocumentParser parser = new DocumentParser(sample_text);
        parser.tokenize();
        parser.filter_tokens(3);
        TokenAnalyzer analyzer = new TokenAnalyzer(parser.tokens);
        analyzer.calculate_frequencies();
        Map<String, Integer> top_frequencies = analyzer.get_top_frequencies(5);
        System.out.println(top_frequencies);
    }
}