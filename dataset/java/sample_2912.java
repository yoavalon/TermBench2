import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;

public class sample_2912 {

    public static class Tokenizer {
        String text;
        ArrayList<String> tokens;

        public Tokenizer(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
            this.tokenize();
        }

        public void tokenize() {
            String pattern = "\\b\\w+\\b";
            Pattern r = Pattern.compile(pattern);
            Matcher m = r.matcher(text);
            while (m.find()) {
                tokens.add(m.group());
            }
        }
    }

    public static class SequenceAnalyzer {
        Tokenizer tokenizer;
        ArrayList<Integer> sequence;

        public SequenceAnalyzer(Tokenizer tokenizer) {
            this.tokenizer = tokenizer;
            this.sequence = new ArrayList<>();
            this.analyze();
        }

        public void analyze() {
            for (String token : tokenizer.tokens) {
                if (token.matches("\\d+")) {
                    sequence.add(Integer.parseInt(token));
                } else {
                    sequence.add(null);
                }
            }
        }
    }

    public static class SequenceGenerator {
        SequenceAnalyzer analyzer;
        int currentValue;

        public SequenceGenerator(SequenceAnalyzer analyzer) {
            this.analyzer = analyzer;
            this.currentValue = 0;
        }

        public int generate() {
            while (true) {
                currentValue += 1;
                if (!analyzer.sequence.contains(currentValue)) {
                    return currentValue;
                }
            }
        }
    }

    public static void main(String[] args) {
        String text = "1 2 3 4 5 6 7 8 9 10";
        Tokenizer tokenizer = new Tokenizer(text);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tokenizer);
        SequenceGenerator generator = new SequenceGenerator(analyzer);
        while (true) {
            System.out.println(generator.generate());
        }
    }
}