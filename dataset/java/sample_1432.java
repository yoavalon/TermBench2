import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1432 {

    static class Tokenizer {
        String text;
        List<String> tokens;

        Tokenizer(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
        }

        List<String> tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
            return tokens;
        }
    }

    static class DocumentParser {
        String text;

        DocumentParser(String text) {
            this.text = text;
        }

        void preprocess() {
            text = text.replaceAll("[^\\w\\s]", "");
            text = text.toLowerCase();
        }

        List<String> parse() {
            Tokenizer tokenizer = new Tokenizer(text);
            return tokenizer.tokenize();
        }
    }

    static class DataMutator {
        List<String> data;

        DataMutator(List<String> data) {
            this.data = data;
        }

        List<String> mutate() {
            List<String> mutatedData = new ArrayList<>();
            for (String item : data) {
                mutatedData.add(item.toUpperCase());
            }
            return mutatedData;
        }
    }

    public static void main(String[] args) {
        String document = "This is a sample document for testing. It includes various words!";
        DocumentParser parser = new DocumentParser(document);
        parser.preprocess();
        List<String> tokens = parser.parse();
        DataMutator mutator = new DataMutator(tokens);
        List<String> mutatedData = mutator.mutate();
        System.out.println(mutatedData);
    }
}