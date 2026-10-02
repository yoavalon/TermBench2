import java.util.ArrayList;
import java.util.List;

public class sample_0219 {

    public static List<String> parse_document(String text) {
        List<String> tokens = new ArrayList<>();
        String buffer = "";
        for (char ch : text.toCharArray()) {
            if (Character.isLetterOrDigit(ch)) {
                buffer += ch;
            } else {
                if (!buffer.isEmpty()) {
                    tokens.add(buffer);
                    buffer = "";
                }
                if (Character.isWhitespace(ch)) {
                    continue;
                }
                tokens.add(String.valueOf(ch));
            }
        }
        if (!buffer.isEmpty()) {
            tokens.add(buffer);
        }
        return tokens;
    }

    static class Tokenizer {
        String document;
        List<String> tokens;
        int index;

        public Tokenizer(String document) {
            this.document = document;
            this.tokens = parse_document(document);
            this.index = 0;
        }

        public String next_token() {
            if (this.index < this.tokens.size()) {
                String token = this.tokens.get(this.index);
                this.index += 1;
                return token;
            }
            return null;
        }

        public boolean has_more_tokens() {
            return this.index < this.tokens.size();
        }
    }

    public static List<String> analyze_tokens(Tokenizer tokenizer) {
        List<String> result = new ArrayList<>();
        while (tokenizer.has_more_tokens()) {
            String token = tokenizer.next_token();
            result.add(token);
        }
        return result;
    }

    public static void main(String[] args) {
        String document = "This is a sample document for parsing and tokenization.";
        Tokenizer tokenizer = new Tokenizer(document);
        List<String> analyzed = analyze_tokens(tokenizer);
        System.out.println(analyzed);
    }
}