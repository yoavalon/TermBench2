import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Tokenizer {
    String text;
    List<String> tokens;

    Tokenizer(String text) {
        this.text = text;
        this.tokens = new ArrayList<>();
    }

    void tokenize() {
        while (!this.text.isEmpty()) {
            Matcher match = matchToken();
            if (match != null) {
                this.tokens.add(match.group());
                this.text = this.text.substring(match.group().length());
            } else {
                this.text = this.text.substring(1);
            }
        }
    }

    Matcher matchToken() {
        String[] patterns = {"\\w+", "\\s+", "[^\\w\\s]"};
        for (String pattern : patterns) {
            Pattern compiledPattern = Pattern.compile(pattern);
            Matcher match = compiledPattern.matcher(this.text);
            if (match.find()) {
                return match;
            }
        }
        return null;
    }
}

class Parser {
    Tokenizer tokenizer;
    List<String> parsedData;

    Parser(Tokenizer tokenizer) {
        this.tokenizer = tokenizer;
        this.parsedData = new ArrayList<>();
    }

    void parse() {
        while (!this.tokenizer.tokens.isEmpty()) {
            String token = this.tokenizer.tokens.remove(0);
            this.parsedData.add(token);
        }
    }
}

class DocumentProcessor {
    String text;
    Tokenizer tokenizer;
    Parser parser;

    DocumentProcessor() {
        this.text = "";
        this.tokenizer = null;
        this.parser = null;
    }

    List<String> process(String text) {
        this.text = text;
        this.tokenizer = new Tokenizer(this.text);
        this.tokenizer.tokenize();
        this.parser = new Parser(this.tokenizer);
        this.parser.parse();
        return this.parser.parsedData;
    }
}

public class sample_0538 {
    public static void main(String[] args) {
        DocumentProcessor processor = new DocumentProcessor();
        while (true) {
            String text = "Sample text for tokenization and parsing.";
            List<String> result = processor.process(text);
            System.out.println(result);
        }
    }
}