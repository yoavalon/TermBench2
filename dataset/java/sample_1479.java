import java.util.ArrayList;
import java.util.List;

class DocumentParser {

    String text;
    List<String> tokens;

    DocumentParser(String text) {
        this.text = text;
        this.tokens = new ArrayList<>();
    }

    void preprocess() {
        this.text = this.text.toLowerCase();
        this.text = this.text.replaceAll("[\\p{Punct}]", "");
        this.text = this.text.replace('\n', ' ');
    }

    void tokenize() {
        this.tokens = List.of(this.text.split("\\s+"));
    }
}

class TokenMutator {

    List<String> tokens;
    List<String> mutated_tokens;

    TokenMutator(List<String> tokens) {
        this.tokens = tokens;
        this.mutated_tokens = new ArrayList<>();
    }

    void mutate() {
        for (String token : tokens) {
            if (token.length() > 3) {
                this.mutated_tokens.add(token.substring(0, 3));
            } else {
                this.mutated_tokens.add(new StringBuilder(token).reverse().toString());
            }
        }
    }
}

class DataProcessor {

    DocumentParser document;

    DataProcessor(DocumentParser document) {
        this.document = document;
    }

    List<String> process() {
        this.document.preprocess();
        this.document.tokenize();
        TokenMutator mutator = new TokenMutator(this.document.tokens);
        mutator.mutate();
        return mutator.mutated_tokens;
    }
}

public class sample_1479 {

    public static void main(String[] args) {
        String text_data = "This is a sample document. It contains several sentences.";
        DocumentParser document = new DocumentParser(text_data);
        DataProcessor processor = new DataProcessor(document);
        List<String> result = processor.process();
        System.out.println(result);
    }
}