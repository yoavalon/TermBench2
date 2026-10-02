import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;

public class sample_0546 {

    static class DocumentParser {
        String text;
        List<String> tokens;

        DocumentParser(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
        }

        void tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
        }

        void process_tokens() {
            List<String> processed_tokens = new ArrayList<>();
            for (String token : tokens) {
                processed_tokens.add(token.toLowerCase());
            }
            tokens = processed_tokens;
        }
    }

    static class Tokenizer {
        DocumentParser parser;

        Tokenizer(DocumentParser parser) {
            this.parser = parser;
        }

        void run() {
            parser.tokenize();
            parser.process_tokens();
        }
    }

    static class Processor {
        Tokenizer tokenizer;

        Processor(Tokenizer tokenizer) {
            this.tokenizer = tokenizer;
        }

        void execute() {
            while (true) {
                tokenizer.run();
            }
        }
    }

    public static void main(String[] args) {
        String text = "Document parsing and lexical tokenization is crucial for natural language processing.";
        DocumentParser parser = new DocumentParser(text);
        Tokenizer tokenizer = new Tokenizer(parser);
        Processor processor = new Processor(tokenizer);
        processor.execute();
    }
}