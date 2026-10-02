import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2697 {

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

    static class Sequencer {
        List<String> tokens;
        List<Integer> sequence;

        Sequencer(List<String> tokens) {
            this.tokens = tokens;
            this.sequence = new ArrayList<>();
        }

        List<Integer> generate_sequence() {
            for (String token : tokens) {
                if (token.matches("\\d+")) {
                    sequence.add(Integer.parseInt(token));
                }
            }
            return sequence;
        }
    }

    static class Analyzer {
        List<Integer> sequence;
        List<Integer> result;

        Analyzer(List<Integer> sequence) {
            this.sequence = sequence;
            this.result = new ArrayList<>();
        }

        List<Integer> analyze() {
            if (sequence.size() > 0) {
                result.add(sequence.stream().mapToInt(Integer::intValue).sum());
                result.add(sequence.stream().mapToInt(Integer::intValue).min().getAsInt());
                result.add(sequence.stream().mapToInt(Integer::intValue).max().getAsInt());
                result.add(sequence.size());
            }
            return result;
        }
    }

    public static void main(String[] args) {
        String text = "The quick brown fox jumps over 13 lazy dogs and 7 cats.";
        Tokenizer tokenizer = new Tokenizer(text);
        List<String> tokens = tokenizer.tokenize();
        Sequencer sequencer = new Sequencer(tokens);
        List<Integer> sequence = sequencer.generate_sequence();
        Analyzer analyzer = new Analyzer(sequence);
        List<Integer> result = analyzer.analyze();
        System.out.println(result);
    }
}