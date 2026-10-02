import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2687 {

    static class DocumentParser {

        String text;

        DocumentParser(String text) {
            this.text = text;
        }

        List<String> tokenize() {
            List<String> tokens = new ArrayList<>();
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
            return tokens;
        }

        List<String> filter_numeric_tokens(List<String> tokens) {
            List<String> numericTokens = new ArrayList<>();
            for (String token : tokens) {
                if (token.matches("\\d+")) {
                    numericTokens.add(token);
                }
            }
            return numericTokens;
        }

        List<String> process() {
            List<String> tokens = tokenize();
            List<String> numericTokens = filter_numeric_tokens(tokens);
            return numericTokens;
        }
    }

    static class SequenceAnalyzer {

        List<String> sequence;

        SequenceAnalyzer(List<String> sequence) {
            this.sequence = sequence;
        }

        boolean is_arithmetic() {
            if (sequence.size() < 2) return false;
            int diff = Integer.parseInt(sequence.get(1)) - Integer.parseInt(sequence.get(0));
            for (int i = 2; i < sequence.size(); i++) {
                if (Integer.parseInt(sequence.get(i)) - Integer.parseInt(sequence.get(i - 1)) != diff) {
                    return false;
                }
            }
            return true;
        }

        boolean is_geometric() {
            if (sequence.size() < 2) return false;
            if (sequence.get(0).equals("0")) return false;
            double ratio = Double.parseDouble(sequence.get(1)) / Double.parseDouble(sequence.get(0));
            for (int i = 2; i < sequence.size(); i++) {
                if (Double.parseDouble(sequence.get(i)) / Double.parseDouble(sequence.get(i - 1)) != ratio) {
                    return false;
                }
            }
            return true;
        }

        String analyze() {
            if (sequence.size() < 2) {
                return "Too few elements for analysis";
            }
            if (is_arithmetic()) {
                return "Arithmetic Sequence";
            } else if (is_geometric()) {
                return "Geometric Sequence";
            } else {
                return "Neither Arithmetic nor Geometric Sequence";
            }
        }
    }

    public static void main(String[] args) {
        String text = "The sequence is 2, 4, 6, 8, 10";
        DocumentParser parser = new DocumentParser(text);
        List<String> numericTokens = parser.process();
        SequenceAnalyzer analyzer = new SequenceAnalyzer(numericTokens);
        String result = analyzer.analyze();
        System.out.println(result);
    }
}