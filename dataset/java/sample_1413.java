import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1413 {

    static class TextProcessor {
        private String text;

        public TextProcessor(String text) {
            this.text = text;
        }

        public List<String> tokenize() {
            List<String> tokens = new ArrayList<>();
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
            return tokens;
        }

        public List<String> normalize(List<String> tokens) {
            List<String> normalizedTokens = new ArrayList<>();
            for (String token : tokens) {
                normalizedTokens.add(token.toLowerCase());
            }
            return normalizedTokens;
        }
    }

    static class MutationEngine {
        private List<String> tokens;

        public MutationEngine(List<String> tokens) {
            this.tokens = tokens;
        }

        public List<String> apply_mutation() {
            List<String> mutatedTokens = new ArrayList<>();
            for (String token : tokens) {
                String mutatedToken;
                if (token.length() > 3) {
                    mutatedToken = token.charAt(0) + token.charAt(token.length() - 1) + new StringBuilder(token.substring(1, token.length() - 1)).reverse().toString();
                } else {
                    mutatedToken = new StringBuilder(token).reverse().toString();
                }
                mutatedTokens.add(mutatedToken);
            }
            return mutatedTokens;
        }
    }

    static class DatasetGenerator {
        private TextProcessor textProcessor;
        private MutationEngine mutationEngine;

        public DatasetGenerator(String text) {
            this.textProcessor = new TextProcessor(text);
            this.mutationEngine = null;
        }

        public List<String> generate() {
            List<String> tokens = textProcessor.tokenize();
            List<String> normalizedTokens = textProcessor.normalize(tokens);
            this.mutationEngine = new MutationEngine(normalizedTokens);
            List<String> mutatedTokens = mutationEngine.apply_mutation();
            return mutatedTokens;
        }
    }

    public static void main(String[] args) {
        String sampleText = "The quick brown fox jumps over the lazy dog";
        DatasetGenerator datasetGenerator = new DatasetGenerator(sampleText);
        List<String> result = datasetGenerator.generate();
        System.out.println(result);
    }
}