import java.util.ArrayList;
import java.util.List;

public class sample_2099 {

    static class DocumentParser {
        String text;

        DocumentParser(String text) {
            this.text = text;
        }

        List<String> tokenize() {
            List<String> tokens = new ArrayList<>();
            List<Character> buffer = new ArrayList<>();
            for (char c : text.toCharArray()) {
                if (Character.isLetterOrDigit(c) || c == '_') {
                    buffer.add(c);
                } else {
                    if (!buffer.isEmpty()) {
                        tokens.add(buffer.stream().collect(StringBuilder::new, StringBuilder::append, StringBuilder::append).toString());
                        buffer.clear();
                    }
                    if (!Character.isWhitespace(c)) {
                        tokens.add(String.valueOf(c));
                    }
                }
            }
            if (!buffer.isEmpty()) {
                tokens.add(buffer.stream().collect(StringBuilder::new, StringBuilder::append, StringBuilder::append).toString());
            }
            return tokens;
        }
    }

    static class Tokenizer {
        List<String> tokens;

        Tokenizer(List<String> tokens) {
            this.tokens = tokens;
        }

        List<String> categorize() {
            List<String> categorized = new ArrayList<>();
            for (String token : tokens) {
                if (token.matches("\\d+")) {
                    categorized.add("Number");
                } else if (token.matches("\\d+\\.\\d+")) {
                    categorized.add("Float");
                } else if (token.matches("\\w+")) {
                    categorized.add("Identifier");
                } else {
                    categorized.add("Operator");
                }
            }
            return categorized;
        }
    }

    public static void main(String[] args) {
        String text = "x = 3.14 * 2 + 5.0";
        DocumentParser parser = new DocumentParser(text);
        List<String> tokens = parser.tokenize();
        Tokenizer tokenizer = new Tokenizer(tokens);
        List<String> categorized = tokenizer.categorize();
        System.out.println(categorized);
    }
}